# My Own HTTP Server

A simple HTTP server written in **C**, designed to handle basic HTTP requests and serve a static HTML page.  

This project is part of my **tribute series**, where I recreate fundamental software that shaped the tech industry. This one is dedicated to the **HTTP protocol**, the backbone of the modern web.

> I documented the entire process on [dev.to](https://dev.to/wesleybertipaglia) and [my blog](https://wesleybertipaglia.github.io/).  

Check it out and let’s discuss! 🚀  

## Features

- Minimalist HTTP server implementation in C
- Handles basic **GET** requests
- Serves a **static HTML page**
- Organized file structure with `src/` and `include/`
- Easy compilation with `Makefile`

## Project Structure

- `src/`: Server source code.
- `include/`: Header files.
- `Makefile`: File to compile the project.

## How to run

1. Clone this repository:

```bash
git clone https://github.com/wesleybertipaglia/own-http-server.git
```

2. Compile the project:

```bash
make
```

3. Run the server:

```bash
./server
```

4. Access `http://localhost:8080` in your browser to see the response page.

5. To stop the server, press `Ctrl+C` in the terminal where the server is running.

## Possible Improvements
- Support for more HTTP methods (POST, PUT, DELETE, etc.)
- Implement a routing system
- Improve logging for request tracking
- Optimize performance with multi-threading

## Contributing

If you’d like to contribute, feel free to open an issue or submit a pull request. All contributions are welcome!

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
