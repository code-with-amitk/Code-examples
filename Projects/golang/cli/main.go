func main() {
    if len(os.Args) == 2 && os.Args[1] == "daemon" {
        // Daemon Process
        fmt.Println("Daemon process")
        systemusage.Daemon()
    }
    // TODO: Place at end of main() function
    // Once IO worker is launched & Ready, launch the daemon
    // Main Process fork a new process to create a daemon
    cmdDeamon := exec.Command(os.Args[0], "daemon")
    cmdDeamon.Stdout = os.Stdout
    cmdDeamon.Stderr = os.Stderr

    if err := cmdDeamon.Start(); err != nil {
        fmt.Printf("Failed to start daemon: %v\n", err)
        os.Exit(1)
    }
    // In case of graceful shutdown, daemon starts in background
    //return

    // Some other work
  }
