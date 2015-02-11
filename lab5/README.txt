**************************************************************************************
**************************************************************************************
**  Alisa Krivokapic (ak3533)
**  CS3157 Lab #5
**  10/28/14
**************************************************************************************
**************************************************************************************
**
**  PART 1: Everything works as expected.
**
**              a) Write a shell script (mdb-lookup-server-nc.sh) that executes the 
**                pipeline to turn mdb-lookup-cs3157 into a network server using 
**                Netcat and a named pipe.
**              
**              * used mkfifo to create a FIFO special file that could be used by any 
**                process for reading/writing. It serves as a communication channel.
**
**              * made nc listen (server side) on the port that was passed to the
**                script as an argument. 
**              
**             b) Run the mdb-lookup-server-nc-1 & ps ajxfww from another terminal
**                window.
**             
**              * ran the program with the port number as a command line argument;
**                that port number was passed to the script mdb-lookup-server-nc.sh
**                when it was executed from the child process
**
**              * process tree that contains all ancestors and children of this
**                program included below (I also included the tree for ps ajxfww
**                even though this isn't part of the program process tree)
**
**              * files that are shell scripts (for the program process tree): 
**                
**                - ./mdb-lookup-server-nc.sh: 
**                  
**                  script I wrote to turn mdb-lookup-cs3157 into a network server
**                  
**                  
**                - /home/jae/cs3157-pub/bin/mdb-lookup-cs3157: 
**              
**                  script written by Jae to execute mdb-lookup with mdb-cs3157 as
**                  an argument
**          
**             c) Write an improved version called  mdb-lookup-server-nc-2.c               
**              
**              * Fixed printing order using nanosleep() function with 1/3 s interval.
**
**              * Assumed that input for entering port number won't exceed 1000 chars.
**                (Didn't handle invalid port numbers as suggested in the mailing list)
**
**
**  Valgrind output indicated no errors or memory leaks.
**
**
**

Process Tree: 

  914 19129 19129 19129 ?           -1 Ss       0   0:00  \_ sshd: ak3533 [priv] 
19129 19137 19129 19129 ?           -1 S    15555   0:00  |   \_ sshd: ak3533@pts/8  
19137 19139 19139 19139 pts/8    24868 Ss   15555   0:00  |       \_ -bash
19139 24868 24868 19139 pts/8    24868 S+   15555   0:00  |           \_ ./mdb-lookup-server-nc-1 20000
24868 24869 24868 19139 pts/8    24868 S+   15555   0:00  |               \_ /bin/sh ./mdb-lookup-server-nc.sh 20000
24869 24871 24868 19139 pts/8    24868 S+   15555   0:00  |                   \_ cat mypipe-24869
24869 24872 24868 19139 pts/8    24868 S+   15555   0:00  |                   \_ nc -l 20000
24869 24873 24868 19139 pts/8    24868 S+   15555   0:00  |                   \_ /bin/sh /home/jae/cs3157-pub/bin/mdb-lookup-cs3157
24873 24877 24868 19139 pts/8    24868 S+   15555   0:00  |                       \_ /home/jae/cs3157-pub/bin/mdb-lookup /home/jae/cs3157-pub/bin/mdb-cs3157
  914 23506 23506 23506 ?           -1 Ss       0   0:00  \_ sshd: ak3533 [priv] 
23506 23535 23506 23506 ?           -1 S    15555   0:00  |   \_ sshd: ak3533@pts/13 
23535 23536 23536 23536 pts/13   25081 Ss   15555   0:00  |       \_ -bash
23536 25081 25081 23536 pts/13   25081 R+   15555   0:00  |           \_ ps ajxfww


