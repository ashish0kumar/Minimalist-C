# Minimalist HTTPS Client in C

This is a minimalist HTTPS client written in C that connects to a specified server over HTTPS, sends a GET request, and prints the server's response. The client uses OpenSSL for secure communication.

## Features

- Connects to an HTTPS server on port 443
- Sends a simple GET request
- Receives and displays the server response

## Files

`client.c`: The C source code for the HTTPS client.

## How to Use

1. **Install OpenSSL:** Make sure you have OpenSSL installed on your system. You can typically install it using your package manager. For example, on Ubuntu:

```bash
sudo apt-get install libssl-dev
```

2. **Compile the client:**

```bash
gcc -o https_client client.c -lssl -lcrypto
```

3. **Run the client:** Modify the IP address in the `htonl(0x08080808)` line to connect to your desired server. Then, run the client:

```bash
./https_client
```

4. **View the response:** The client will print the server's response to the console.

## Dependencies

- GCC (or any C compiler)
- OpenSSL development libraries

## Notes

- The IP address in the `htonl(0x08080808)` line represents `8.8.8.8`. Change this to the desired server's IP address.
- Ensure your system is set up to handle HTTPS connections and that the server you are connecting to supports them.
