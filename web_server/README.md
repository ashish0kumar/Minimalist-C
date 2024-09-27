# Minimalist Web Server in C

This is a minimalist web server written in C that listens on localhost:8080 and serves the index.html file located in the same directory as the server program. The server listens for incoming HTTP GET requests and responds by serving the requested file.

## Features

- Runs a basic web server on localhost port 8080
- Serves index.html on requests to /index.html
- Uses standard C libraries like sys/socket.h and fcntl.h

## Files

- `server.c`: The C source code for the web server.
- `index.html`: The HTML file served by the server.

## How to Use

1. Compile the server:
    
```bash
gcc -o web_server server.c
```

2. Run the server:

```bash
./web_server
```

3. Access the web page: Open a browser and visit http://localhost:8080/index.html to see the content of index.html.

## Dependencies

- GCC (or any C compiler)
- Linux environment (for sys/socket and sendfile)


## Notes

- Ensure that the index.html file is in the same directory as server.c.
- The server handles only GET requests for HTML files.
