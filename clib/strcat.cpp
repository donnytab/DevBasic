char* strcat(char* dest, const char* src) {
    char* ret = dest;
    assert(dest != nullptr);
    assert(src != nullptr);
    while (*dest != '\0')
      dest++;
    while (*src != '\0')
      *(dest++) = *(src++);
    *dest = '\0';
    return ret;
}
