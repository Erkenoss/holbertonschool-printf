# <p align="center">Printf Project</p>
  
The _printf function is a reproduction of printf function. However, there isn't all the feature for now. 
The function _printf has for objective to display something and depend of the format given. 
There is for now two errors case:

- When the format is NULL.
- When the flag % is followed by an end characters line \0. 

In this two case, the function return -1 to signal an error. 

In successful case, the function return the number of character display in the output. 

# <p align="center">Compilation line</p>

Here, the compilation we use for: 

- gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c

# <p align="center">Requirements</p>

The code has been created on:

- Ubuntu 20.04 LTS
- In C langage
- Betty Style and Documentation
- With VIM editor

# <p align="center">Exemples and test</p>

```
int main(void)
{
        len = _printf("Let's try to printf a simple sentence.\n");
        len2 = printf("Let's try to printf a simple sentence.\n");
        _printf("Length:[%d, %i]\n", len, len);
        printf("Length:[%d, %i]\n", len2, len2);
        _printf("Negative:[%d]\n", -762534);
        printf("Negative:[%d]\n", -762534);
        _printf("Character:[%c]\n", 'H');
        printf("Character:[%c]\n", 'H');
        _printf("String:[%s]\n", "I am a string !");
        printf("String:[%s]\n", "I am a string !");
        len = _printf("Percent:[%%]\n");
        len2 = printf("Percent:[%%]\n");
        _printf("Len:[%d]\n", len);
        printf("Len:[%d]\n", len2);
        _printf("Unknown:[%r]\n");
        printf("Unknown:[%r]\n");
        return (0);
}
```

Give this output:

```

Let's try to printf a simple sentence.
Let's try to printf a simple sentence.
Length:[39, 39]
Length:[39, 39]
Negative:[-762534]
Negative:[-762534]
Character:[H]
Character:[H]
String:[I am a string !]
String:[I am a string !]
Percent:[%]
Percent:[%]
Len:[12]
Len:[12]
Unknown:[%r]
Unknown:[%r]

```

For more information, we suggest you to go on the [man_page](https://github.com/JeremMac/holbertonschool-printf/blob/master/man_3_printf)
        

![Image](https://github.com/JeremMac/holbertonschool-printf/blob/master/flowchart%20printf.drawio.png?raw=true)
