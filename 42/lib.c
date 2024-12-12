//ft_isalpha

int ft_isalpha(int c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

//ft_isdigit
int ft_isdigit(int c)
{
    return (c >= '0' && c <= '9');
}

//ft_isalnum
int ft_isalnum(int c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'));
}

//ft_isascii
int ft_isascii(int c)
{
    return (c >= 0 && c <= 127);
}

//ft_isprint
int ft_isprint(int c)
{
    return (c >= 32 && c <= 126);
}

//ft_strlen
int ft_strlen(const char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return len;
}

//ft_memset
void *ft_memset(void *b, int c, int len)
{
    unsigned char *ptr = b;
    while (len--)
    {
        *ptr = (unsigned char)c;
        ptr++;
    }
    return b;
}

//ft_bzaro
void ft_bzero(void *s, int len)
{
    ft_memset(s, 0, len);
}

//ft_memcpy
void *ft_memcpy(void *dest, const void *src, int n)
{
    unsigned char *d = dest;
    const unsigned char *s = src;
    while (n--)
    {
        *d = *s;
        d++;
        s++;
    }
    return dest;
}

//ft_memmove
void *ft_memmove(void *dest, const void *src, int len)
{
    unsigned char *d = dest;
    const unsigned char *s = src;

    if (s < d)
    {
        d += len;
        s += len;
        while (len--)
        {
            *(--d) = *(--s);
        }
    }
    else
    {
        while (len--)
        {
            *d = *s;
            d++;
            s++;
        }
    }
    return dest;
}

//ft_strlcpy
int ft_strlcpy(char *dst, const char *src, int size)
{
    int i = 0;

    if (size == 0)
        return ft_strlen(src);

    while (src[i] && i < size - 1)
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return ft_strlen(src);
}

//ft_strlcat
int ft_strlcat(char *dst, const char *src, int size)
{
    int i = 0;
    int j = 0;

    while (dst[i] && i < size)
        i++;
    
    while (src[j] && i + j < size - 1)
    {
        dst[i + j] = src[j];
        j++;
    }
    if (i < size)
        dst[i + j] = '\0';
    return i + ft_strlen(src);
}

//ft_toupper
int ft_toupper(int c)
{
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 'A';
    return c;
}

//ft_tolower
int ft_tolower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    return c;
}

//ft_strchr
char *ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == (char)c)
            return (char *)s;
        s++;
    }
    if (c == '\0')
        return (char *)s;
    return 0;
}

//ft_strrchr
char *ft_strrchr(const char *s, int c)
{
    char *last = 0;

    while (*s)
    {
        if (*s == (char)c)
            last = (char *)s;
        s++;
    }
    if (c == '\0')
        return (char *)s;
    return last;
}

//ft_strncmp
int ft_strncmp(const char *s1, const char *s2, int n)
{
    while (n && *s1 && *s1 == *s2)
    {
        s1++;
        s2++;
        n--;
    }
    if (n == 0)
        return 0;
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

//ft_memchr
void *ft_memchr(const void *s, int c, int n)
{
    unsigned char *ptr = (unsigned char *)s;
    while (n--)
    {
        if (*ptr == (unsigned char)c)
            return ptr;
        ptr++;
    }
    return 0;
}

//ft_memcmp
int ft_memcmp(const void *s1, const void *s2, int n)
{
    unsigned char *p1 = (unsigned char *)s1;
    unsigned char *p2 = (unsigned char *)s2;
    while (n--)
    {
        if (*p1 != *p2)
            return *p1 - *p2;
        p1++;
        p2++;
    }
    return 0;
}

//ft_strnstr
char *ft_strnstr(const char *haystack, const char *needle, int len)
{
    if (*needle == '\0')
        return (char *)haystack;

    while (*haystack && len)
    {
        if (len >= ft_strlen(needle) && !ft_strncmp(haystack, needle, ft_strlen(needle)))
            return (char *)haystack;
        haystack++;
        len--;
    }
    return 0;
}

//ft_atoi
int ft_atoi(const char *str)
{
    int result = 0;
    int sign = 1;

    // Ignorar espacios en blanco al principio
    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;

    // Manejar signo (+/-)
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }

    // Convertir números
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
    }

    return result * sign;
}


//ft_calloc
void *ft_calloc(int nmemb, int size)
{
    void *ptr;

    // Si nmemb o size es 0, calloc debe devolver un puntero válido que puede ser pasado a free()
    if (nmemb == 0 || size == 0)
        return malloc(0);

    ptr = malloc(nmemb * size);
    if (ptr == 0)
        return 0;

    // Inicializa la memoria a cero
    ft_bzero(ptr, nmemb * size);
    return ptr;
}


//ft_strdup
char *ft_strdup(const char *s1)
{
    int len = ft_strlen(s1);
    char *copy = (char *)malloc(len + 1);
    
    if (copy == 0)
        return 0;

    ft_memcpy(copy, s1, len + 1);  // Incluye el carácter nulo '\0'
    return copy;
}


