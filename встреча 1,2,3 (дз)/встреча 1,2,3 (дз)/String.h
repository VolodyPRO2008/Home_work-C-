#ifndef STRING_H
#define STRING_H

class String {
private:
    char* data;
    int length;
    static int objectCount;

public:
    String();
    explicit String(int size);
    String(const char* str);
    ~String();
    void input();
    void output() const;
    static int getObjectCount();
};

#endif