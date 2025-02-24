# 42-get_next_line

In this project, we will learn:

- What static variables are,  
- How files are opened, read, and closed in an OS,  
- How files are interpreted by a programming language.  

**NOTE:** Since this is a 42 school project, I must follow their norm.  

## Example of Interpretation in a Programming Language  

When a language like Python or C opens a text file, it reads a sequence of encoded characters (e.g., in UTF-8 or ASCII). If it were a binary file (such as an image or an executable file), the program would have to decode it differently.  

If you want to return one line at a time from a text file, you can write a function that uses sequential reading. For example, in Python:  

```python
def get_next_line(file_path): 
    with open(file_path, "r") as file: 
        for line in file: 
            yield line.strip()  # Returns one line at a time without the newline character 

file_reader = get_next_line("text.txt") 
print(next(file_reader))  # Prints the first line  
print(next(file_reader))  # Prints the second line  
```

In today's project, we will do exactly this but in the C language.  

## Static Variables  

First of all, we need to understand what Static Variables are. As you know, local variables exist only within the scope of the function they belong to.  

Referring to a variable `x` outside the function in which `x` was defined is equivalent to initializing a new variable (this does not cause compilation errors but can lead to various bugs and unexpected behaviors), while working with a variable that does not exist because it is limited to an internal function will result in a compilation error.  

A static variable behaves like a global variable with local scope, meaning it can only be used within the function where it is defined, but its value is retained between function calls.  

This is a static variable:  

```c
char *get_next_line(int fd)
{
    static char *buffer;
    // ... rest of the function
}
```

## Let's Start with the Code  

We begin with the main program, `get_next_line.c`.  

First, we need to write the function:  

```c
char *get_next_line(int fd)
```

```c
if (fd < 0 || BUFFER_SIZE <= 0)
    return (NULL);
```
This line checks whether it makes sense to proceed: if the file descriptor is less than 0, it means that opening the file has failed (in that case, `fd` takes the value -1), and if the macro `BUFFER_SIZE` is not greater than zero (i.e., if the file is empty), there is no point in proceeding and nothing can be read.  

---  

**Remember:**  

**File Descriptor:**  
It is an integer number that the operating system assigns to represent (describe) a file or a stream (e.g., standard input/output/error) opened in a program. It serves as a reference for read, write, or close operations.  

**Macro:**  
It is a definition in the C preprocessor that replaces a name with a value or a portion of code. It is used to define constants (e.g., `#define BUFFER_SIZE 1024`) or to create simplified inline functions.  

**Difference between Macro and Variable:**  
The main difference between a macro and a variable in C lies in how they are handled by the compiler and their impact on performance and memory.  

*Use a macro if you need to define a constant (e.g., `#define PI 3.1415`).*  
*Use a variable if the value might change during execution or if a specific type is needed.*  
*For numeric constants, it is better to use `const` instead of `#define` (`const int BUFFER_SIZE = 1024;`), because it provides better type control and facilitates debugging.*  

---  

```c
if (check_newline(buffer))
```

`check_newline(buffer)` checks if there is a newline character (`\n`) in the buffer.  
If there is a newline, it executes the `if` block; otherwise, it moves to the next part.  

```c
line = extract_line(buffer);
```

`extract_line(buffer)` extracts the first line contained in the buffer (up to and including the first `\n`).  

```c
buffer = fix_buffer(buffer);
```

`fix_buffer(buffer)` updates the buffer by removing the extracted line, leaving only the remaining content (what comes after `\n`).  

```c
if (!buffer)
    buffer = create_buffer(fd, buffer);
```

If the buffer is empty after removing the line, it is reloaded with new data from `fd` using `create_buffer(fd, buffer)`.  

```c
return (line);
```

If there was a `\n` in the initial buffer, the function returns the extracted line and terminates.  

**Case when there is no `\n` in the buffer**  
If no `\n` is found, then the code proceeds:  

```c
buffer = create_buffer(fd, buffer);
```

Reloads the buffer by reading more data from the file descriptor `fd`.  

```c
if (!buffer)
    return (NULL);
```

If reading produced nothing (e.g., EOF or error), the function returns `NULL`, indicating there are no more lines to read.  

```c
line = extract_line(buffer);
buffer = fix_buffer(buffer);
```

If the buffer still has data:  
- Extracts a new line with `extract_line(buffer)`.  
- Removes the extracted line from the buffer with `fix_buffer(buffer)`.  

```c
return (line);
```

Returns the extracted line.  

**Summary of How It Works:**  
- If the buffer already has a `\n`, it extracts the line, updates the buffer, and immediately returns the line.  
- If there is no `\n`, it reads more data from the file (`create_buffer`).  
- If reading produces nothing, it returns `NULL`.  
- If reading is successful, it extracts the line, updates the buffer, and returns it.  

## Sources and Further Reading  

[Video Explanation](https://www.youtube.com/watch?v=8E9siq7apUU)

