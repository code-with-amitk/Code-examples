GOOS=darwin     GOARCH=arm64    go build -trimpath -ldflags '-w -s'    -o bin/mac_binary                cli/*.go
GOOS=linux      GOARCH=amd64    go build -trimpath -ldflags '-w -s'    -o bin/linux_binary              cli/*.go
GOOS=windows    GOARCH=amd64    go build -trimpath -ldflags '-w -s'    -o bin/windows.exe        cli/*.go
