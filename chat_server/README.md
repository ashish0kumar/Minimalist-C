# Minimalist Chat Server in C

This is a minimalist chat server-client setup written in C using socket programming and the `poll()` system call to handle multiple file descriptors, allowing the server to receive and send messages between connected clients.

## Files

- `server.c`: Source code for the server that listens for incoming connections and handles communication between clients.
- `client.c`: Source code for the client that connects to the server and participates in the chat.


## How to Use

1. **Compile the Server and Client:**

```bash
gcc -o server server.c
gcc -o client client.c
```

2. **Run the Server and Client in different windows:**

```bash
./server
./client
```
The server will start and listen for incoming client connections on port `9999`.

The client will connect to the server, and you can start sending and receiving messages.

3. **Chat Interaction**

- The server will print messages sent by the client.
- The client will display messages sent by the server.
- Both client and server can type messages in their respective terminals, and the messages will be relayed to each other.


## How It Works

**Key Functions in `server.c` and `client.c`:**

- `socket()`: Creates a socket for communication.
- `bind()`: Binds the socket to a specific IP address and port (server-side).
- `listen()`: Listens for incoming client connections (server-side).
- `accept()`: Accepts a new client connection (server-side).
- `connect()`: Connects to the server (client-side).
- `poll()`: Monitors multiple file descriptors (stdin and socket) for incoming data.
- `read()`: Reads input from the standard input (keyboard) or socket.
- `send()`: Sends messages to the other party (client or server).
- `recv()`: Receives messages from the other party.

**Polling Mechanism:**

Both the server and client use `poll()` to monitor two file descriptors:

1. `stdin` (Standard Input) for user input.
2. The socket for incoming messages from the other party.

When a file descriptor is ready (either user input or data from the socket), the appropriate action is taken (read from stdin or receive/send data from/to the socket).


## Notes

- The server and client both operate in an infinite loop, continuously polling for new data and handling messages.
- This is a minimalist chat application designed for simplicity and demonstration purposes. It can be expanded to handle multiple clients or incorporate more advanced features like message broadcasting or encryption.
