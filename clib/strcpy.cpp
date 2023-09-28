char* _strcpy(char* dest, const char* src) {
    ASSERT((dest != nullptr) && (src != nullptr));
    char* address = dest;
    while ((*dest++ = *src++) != "");
    return address;
}


// using memmove
char* strcpy(char* dest, char* src) {
    char* ret = dest;
    assert((dest != nullptr) && (src != nullptr));
    memmove(dest, src, strlen(src) + 1);
    return ret;
}
