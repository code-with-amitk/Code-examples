package systemusage

import (
    "bufio"
    "bytes"
    "fmt"
    "log"
    "os"
    "os/exec"
    "path/filepath"
    "runtime"
    "sort"
    "strconv"
    "strings"
    "time"

    "github.com/shirou/gopsutil/v4/cpu"
    "github.com/shirou/gopsutil/v4/process"
)

var cpuLogFilePath, gpuLogFilePath string

func init() {
    switch runtime.GOOS {
    case "windows":
        cpuLogFilePath = "C:\\temp\\cpu_usage.log" // Use a generic path for testing
        gpuLogFilePath = "C:\\temp\\gpu_usage.log" // Use a generic path for testing
    default:
        cpuLogFilePath = "/tmp/cpu_usage.log"
        gpuLogFilePath = "/tmp/gpu_usage.log"
    }
}

type ProcessInfo struct {
    PID  int32
    Name string
    CPU  float64
}

type GPUProcessInfo struct {
    Timestamp   string
    GPUName     string
    PID         int
    ProcessName string
    Consumption float64
}

func GetLogger(file string) (*log.Logger, *os.File) {
    // Ensure the directory exists
    dir := filepath.Dir(file)
    if _, err := os.Stat(dir); os.IsNotExist(err) {
        fmt.Printf("Directory %s does not exist, attempting to create\n", dir)
        err = os.MkdirAll(dir, 0755)
        if err != nil {
            log.Fatalf("Failed to create directory %s: %v\n", dir, err)
        }
    }

    // Check if the log file already exists
    if _, err := os.Stat(file); err == nil {
        fmt.Printf("Log file %s already exists, attempting to delete\n", file)
        err = os.Remove(file)
        if err != nil {
            log.Fatalf("Failed to delete existing log file %s: %v\n", file, err)
        } else {
            fmt.Printf("Existing log file %s deleted successfully\n", file)
        }
    } else if os.IsNotExist(err) {
        fmt.Printf("Log file %s does not exist, attempting to create\n", file)
    }

    // Create and open a new log file
    fmt.Printf("Attempting to create log file %s\n", file)
    logFile, err := os.OpenFile(file, os.O_CREATE|os.O_APPEND|os.O_WRONLY, 0644)
    if err != nil {
        log.Fatalf("Failed to open log file %s: %v\n", file, err)
    } else {
        fmt.Printf("Log file %s created successfully\n", file)
    }

    // Create a new logger that writes to the log file
    logger := log.New(logFile, "INFO: ", log.Ldate|log.Ltime|log.Lshortfile)

    return logger, logFile
}

// Fetchs GPU usage information using nvidia-smi command
func GetGPUUsage() ([]GPUProcessInfo, error) {
    // Execute the nvidia-smi command to get GPU usage
    cmd := exec.Command("nvidia-smi", "--query-compute-apps=timestamp,gpu_name,pid,process_name,used_gpu_memory", "--format=csv,noheader,nounits")
    var out bytes.Buffer
    cmd.Stdout = &out

    if err := cmd.Run(); err != nil {
        return nil, err
    }

    scanner := bufio.NewScanner(&out)
    var processes []GPUProcessInfo

    // Parse the output line by line
    for scanner.Scan() {
        line := scanner.Text()
        fields := strings.Split(line, ", ")
        if len(fields) != 5 {
            continue
        }

        pid, err := strconv.Atoi(fields[2])
        if err != nil {
            continue
        }

        consumption, err := strconv.ParseFloat(fields[4], 64)
        if err != nil {
            continue
        }

        // Append parsed data to the processes slice
        processes = append(processes, GPUProcessInfo{
            Timestamp:   fields[0],
            GPUName:     fields[1],
            PID:         pid,
            ProcessName: fields[3],
            Consumption: consumption,
        })
    }

    return processes, scanner.Err()
}

func Daemon() {
    // Initialize the loggers
    cpuLogger, cpuLogFile := GetLogger(cpuLogFilePath)
    defer cpuLogFile.Close()
    gpuLogger, gpuLogFile := GetLogger(gpuLogFilePath)
    defer gpuLogFile.Close()

    // CPU usage threshold in percentage
    threshold := 0.25

    // Daemon will run forever
    for {
        // Monitor CPU usage
        usage, err := cpu.Percent(time.Second, false)
        if err != nil {
            cpuLogger.Printf("failed to get CPU usage: %v", err)
            continue
        }

        // If CPU usage is above the threshold, get and log process information
        if usage[0] > threshold {
            processes, err := process.Processes()
            if err != nil {
                cpuLogger.Printf("failed to get processes: %v", err)
                continue
            }

            var processInfos []ProcessInfo

            for _, p := range processes {
                cpuPercent, err := p.CPUPercent()
                if err != nil {
                    continue
                }

                name, err := p.Name()
                if err != nil {
                    continue
                }

                // Append process information to the processInfos slice
                processInfos = append(processInfos, ProcessInfo{
                    PID:  p.Pid,
                    Name: name,
                    CPU:  cpuPercent,
                })
            }

            // Sort processes by CPU usage in descending order
            sort.Slice(processInfos, func(i, j int) bool {
                return processInfos[i].CPU > processInfos[j].CPU
            })

            cpuLogger.Printf("---")
            // Log top 3 CPU consuming processes
            for i := 0; i < len(processInfos) && i < 3; i++ {
                cpuLogger.Printf("PID: %d, Name: %s, CPU Usage: %.2f%%", processInfos[i].PID, processInfos[i].Name, processInfos[i].CPU)
            }
        }

        // Monitor GPU usage
        gpuProcesses, err := GetGPUUsage()
        if err != nil {
            gpuLogger.Printf("failed to get GPU usage: %v", err)
        } else {
            // Sort GPU processes by memory consumption in descending order
            sort.Slice(gpuProcesses, func(i, j int) bool {
                return gpuProcesses[i].Consumption > gpuProcesses[j].Consumption
            })

            gpuLogger.Printf("---")
            // Log top 3 GPU consuming processes
            for i := 0; i < len(gpuProcesses) && i < 3; i++ {
                gpuLogger.Printf("%s %s %d %s %.2f%%", gpuProcesses[i].Timestamp, gpuProcesses[i].GPUName, gpuProcesses[i].PID, gpuProcesses[i].ProcessName, gpuProcesses[i].Consumption)
            }
            time.Sleep(5 * time.Second) // Adjust the interval as needed
        }

        // Sleep for 5 seconds before the next iteration
        time.Sleep(5 * time.Second) // Adjust the interval as needed
    }
}
