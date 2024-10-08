# 🔐🌍 Minimalist HTTPS Server in C

This is a minimalist HTTPS server written in C that serves an HTML file over a secure connection. The server uses OpenSSL for SSL/TLS support and listens on port `8080`.

![chat_server](/screenshots/https_server.png)

## 📂 Files

- `server.c`: The C source code for the HTTPS server.
- `index.html`: The HTML file served by the server.
- `server.crt`: The self-signed SSL certificate (generated by the user).
- `server.key`: The private key for the SSL certificate (generated by the user).

## 🚀 How to Use

1. **Install OpenSSL:** Ensure you have OpenSSL installed on your system. You can install it using your package manager. For example, on Ubuntu:

```bash
sudo apt-get install openssl libssl-dev
```

2. **Generate SSL Certificate and Key:** Navigate to the directory where the server files are located and run the following commands to generate a self-signed SSL certificate and private key:

```bash
openssl genrsa -out server.key 2048
openssl req -new -x509 -key server.key -out server.crt -days 365
```

You will be prompted to fill out some information for the certificate. You can just hit Enter to leave the defaults, but make sure to set the "Common Name" (CN) to the `hostname` you will be using (i.e. `localhost` as we will be testing locally). The generated files will be `server.crt` and `server.key`.

3. **Compile the server:**

```bash
gcc -o server server.c -lssl
```

4. **Run the server:**

```bash
./server
```

5. **Access the server:** Open a web browser and navigate to `https://localhost:8080/index.html`. Since the server uses a self-signed certificate, you may receive a warning about the security of the connection. You can proceed to the site.

## ⚙️ How It Works

The `server.c` file sets up a TCP socket, listens for incoming connections, and serves the `index.html` file over a secure SSL connection. It responds to `HTTP GET` requests and handles requests for the `index.html` file specifically.

## 📦 Dependencies

`OpenSSL`: Required for SSL/TLS support.

## 🗒️ Notes

- Ensure the `server.crt` and `server.key` files are in the same directory as the executable.
- This server is for educational purposes and may not be secure for production use.
