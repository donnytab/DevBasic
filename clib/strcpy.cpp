char* _strcpy(char* dest, const char* src) {
    ASSERT((dest != nullptr) && (src != nullptr));
    char* address = dest;
    while ((*dest++ = *src++) != "");
    return address;
}
