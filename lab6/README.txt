/////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                     //
// Alisa Krivokapic (ak3533)                                                                           //
// CS 3157 Lab 6                                                                                       //
// November 8, 2014                                                                                    //
//                                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////////////////////

//
//  Part1: mdb-lookup-server using sockets API: works as expected
//
    * Write a program that displays all the records containing the search string entered by a user
      on the client side. All the records will be displayed if the client presses <ENTER>.
      The search criteria will use up to the first 5 characters from the search string entered.
      The program keeps running, allowing for another search string to be entered. The user on the
      client side can can terminate it by pressing <Ctrl-D>. The server communicates with the client
      via a socket. The database name and the port number are specified as command line arguments.
      The server handles only one client at a time.

//
//  Solution details:
//
    * configuring the server socket:
      - the socket socket() API function is used to create the TCP socket that uses IP 
      - the sockaddr_in structure is set up with the information about the server itself, 
        and INADDR_ANY constant is used to enable receiving client request on any IP address
        the server supplies. The port is specifed by second command line argument.
                      
    * binding and listening:
      - a client application connects to a server's IP address and port, while a server
        binds to its own address and port using the bind() socket API function. When the
        server socket is bound, it listens for incoming connections on the socket by calling
        the listen() socket API function.
                      
    * accepting and handling a client:
      - the accept() socket API function extracts the first connection in the queue of pending
        connections and creates a new socket to handle that client while the original socket 
        remains open and can accept more connections. 
                      
    * handling a client:
      - every time a client gets accepted, the code for mdb-lookup is run: open database,
        read all the records into memory, run the lookup loop, clean up resources when the
        client is done. After this, the server is ready to handle next client.
                      
    * fdopen() was used to associate the stream pointer with the socket and return it to
      be passed to fgets() function. The fclose() is then used to close the socket.
                    
    * send() socket API function is used to send response records to the client
      - the last line sent is a blank line to mark the end of a search result
                    
    * signal() API function is called with SIG_IGN specified as the second argument so
      we don't terminate when we call send() on a disconnected socket
 
//
//  Part2: Web page downloader http-client
//
    * The program simulates the "wget" command line tool that can be used to download
      a specified web page and save it in the current directory; it should overwrite
      an existing file.
    * The host, port number, and file path are specifed as command line arguments.

//
//  Solution details:
//
    * the program opens a socket connection to the host and specified port number
    * the HTTP GET request with specific format is sent to the server
    * the client receives the requested file content if the request was successful
    * the server terminates the socket connection when it is done sending the file
    * fread()/fwrite() functions were used to read/write to the binary file
