# This is a tutorial file
1. File.h
## This header is used to work with files

```c++
#include <file.h> // or #include "file.h" if you you in folder
```
first is the ```bool fileEx()```:  
 Used for check if file is exist in same directory
Example:
```c++
// check is example.txt is exist
fileEx("example.txt");
```  
If the file exists, the program will return ```true```, else is ```false```  
Alternative is function name ```file_is_exist()```  
If the file exists, the program will print "File exists", else is error massage  
