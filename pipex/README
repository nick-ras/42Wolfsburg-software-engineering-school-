This c project mimics the pipe operator in linux.
In order to use it you have to run "make" and then ex run ./pipex infile "cat -e" "grep a" outfile.
The infile has to exist, but the outfile will be made by program if not existing.
The program opens the infile which ex gets the filedesriptor "3". In first child process it duplicates fd 3 into STDIN, 
and then uses execve with the path of the command "cat" and options "cat" and "-e". Before using execve i made a pipe and duplicated the write end of the pipe into STDOUT (which closes the STDOUT)
The second child read from the read end of the pipe and uses execve on the second argument (new path and options) and output into outfile. Before that, i duplicated fd of outfile into STOUT.
To test run do as shown in line 2.
