import ctypes

# تحميل المكتبة
lib = ctypes.CDLL("./libhuman_math.so")
lib.dot_add.argtypes = [ctypes.c_char_p, ctypes.c_char_p]
lib.dot_add.restype = ctypes.c_void_p
lib.free_string.argtypes = [ctypes.c_void_p]

def hm_add(a, b):
    p = lib.dot_add(str(a).encode(), str(b).encode())
    s = ctypes.string_at(p).decode()
    lib.free_string(p)
    return s

# مثال
print("Human Math Python Example")
print("999... + 1 =", hm_add("9"*50, "1"))
