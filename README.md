# Human Math
مكتبة حسابية عربية للأعداد العملاقة (Big Integers) مكتوبة بـ C++ من الصفر.

## المميزات
- جمع وطرح وضرب وقسمة وباقي لأرقام بأي طول
- خوارزمية Karatsuba للضرب السريع
- دعم الأعداد السالبة
- واجهة C بسيطة للاستخدام من بايثون وأي لغة

## التثبيت
```bash
g++ -shared -fPIC -O3 human_math.cpp -o libhuman_math.so
```

## مثال C++
```cpp
#include "human_math.h"
const char* r = dot_add("99999999999999999999", "1");
// r = "100000000000000000000"
free_string((char*)r);
```

## مثال Python
```python
from human_math import hm_add
print(hm_add("123456789123456789", "987654321987654321"))
```

## الاختبارات
- Diffie-Hellman 2048-bit: ✓
- Hash chain 15s: 1590 عملية
