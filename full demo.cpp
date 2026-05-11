#include "human_math.h"
#include <iostream>

int main() {
    std::cout << "=== Human Math - تجربة كل العمليات ===\n";

    const char* a = "123456789123456789123456789";
    const char* b = "987654321987654321987654321";
    const char* c = "55555555555555555555";
    const char* d = "11111111111111111111";
    const char* e = "12345";
    const char* mod = "1000000007"; // عدد أولي مشهور

    // 1. الجمع
    const char* sum = dot_add(a, b);
    std::cout << "1) الجمع: a + b = " << sum << "\n";

    // 2. الطرح
    const char* sub = dot_sub(sum, c);
    std::cout << "2) الطرح: (a+b) - c = " << sub << "\n";

    // 3. الضرب (Karatsuba)
    const char* mul = dot_mul(sub, d);
    std::cout << "3) الضرب: ((a+b)-c) * d = " << mul << "\n";

    // 4. القسمة
    const char* div = dot_div(mul, e);
    std::cout << "4) القسمة: الناتج / e = " << div << "\n";

    // 5. الباقي
    const char* rem = dot_mod(div, mod);
    std::cout << "5) الباقي: الناتج mod " << mod << " = " << rem << "\n";

    // تعبير كامل: ((a+b-c)*d / e) mod m
    std::cout << "\nالنتيجة النهائية: " << rem << "\n";

    // تحرير الذاكرة
    free_string((char*)sum);
    free_string((char*)sub);
    free_string((char*)mul);
    free_string((char*)div);
    free_string((char*)rem);

    // مثال DH صغير بنفس المكتبة
    const char* g = "5";
    const char* p = "23";
    const char* secret = "6";
    
    const char* g2 = dot_mul(g, g); // 5^2
    const char* g6 = dot_mul(g2, g2); // مبسط
    const char* A = dot_mod(g6, p);
    std::cout << "\nDH test: 5^6 mod 23 = " << A << " (المفروض 8)\n";
    free_string((char*)g2); free_string((char*)g6); free_string((char*)A);

    return 0;
}