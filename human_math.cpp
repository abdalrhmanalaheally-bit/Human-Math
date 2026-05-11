#include "human_math.h"
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>

using std::string;

// ---------- أدوات مساعدة (آمنة) ----------
void free_string(char* str) { free(str); }

const char* return_string(const string& s) {
    char* cstr = (char*)malloc(s.size() + 1);
    std::strcpy(cstr, s.c_str());
    return cstr;
}

int c2i(char c) { return c - '0'; }
char i2c(int n) { return n + '0'; }

void reverse_s(string& s) { std::reverse(s.begin(), s.end()); }

string trim_zeros(const string& s) {
    size_t p = s.find_first_not_of('0');
    return (p == string::npos) ? "0" : s.substr(p);
}

bool less_than(const string& a, const string& b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

// إزالة الإشارة السالبة
string abs(const string& num) {
    return (num[0] == '-') ? num.substr(1) : num;
}

// تحديد الإشارة
int sign(const string& num) {
    return (num[0] == '-') ? -1 : 1;
}

// إعادة الإشارة للعدد
string apply_sign(const string& num, int sgn) {
    if (num == "0") return "0";
    return (sgn == -1) ? "-" + num : num;
}

// ---------- الجمع الأساسي (للأعداد الموجبة) ----------
string simple_add(const string& a, const string& b) {
    string n1 = a, n2 = b;
    reverse_s(n1); reverse_s(n2);
    string res;
    int carry = 0;
    size_t max_len = std::max(n1.size(), n2.size());
    for (size_t i = 0; i < max_len; ++i) {
        int d1 = (i < n1.size()) ? c2i(n1[i]) : 0;
        int d2 = (i < n2.size()) ? c2i(n2[i]) : 0;
        int sum = d1 + d2 + carry;
        res.push_back(i2c(sum % 10));
        carry = sum / 10;
    }
    if (carry) res.push_back(i2c(carry));
    reverse_s(res);
    return res;
}

// ---------- الطرح الأساسي (للأعداد الموجبة, a >= b) ----------
string simple_sub(const string& a, const string& b) {
    string big = a, small = b;
    reverse_s(big); reverse_s(small);
    string res;
    int borrow = 0;
    for (size_t i = 0; i < big.size(); ++i) {
        int dBig = c2i(big[i]);
        int dSmall = (i < small.size()) ? c2i(small[i]) : 0;
        if (dBig < dSmall + borrow) {
            dBig += 10;
            res.push_back(i2c(dBig - dSmall - borrow));
            borrow = 1;
        } else {
            res.push_back(i2c(dBig - dSmall - borrow));
            borrow = 0;
        }
    }
    reverse_s(res);
    return trim_zeros(res);
}

// ---------- 1. .+ (الجمع مع الإشارة) ----------
const char* dot_add(const char* a, const char* b) {
    string sa(a), sb(b);
    int signA = sign(sa), signB = sign(sb);
    string absA = abs(sa), absB = abs(sb);
    
    if (signA == signB) {
        // نفس الإشارة: نجمع ونحتفظ بالإشارة
        return return_string(apply_sign(simple_add(absA, absB), signA));
    } else {
        // إشارات مختلفة: نطرح الأصغر من الأكبر
        if (less_than(absA, absB)) {
            string res = simple_sub(absB, absA);
            return return_string(apply_sign(res, signB));
        } else {
            string res = simple_sub(absA, absB);
            return return_string(apply_sign(res, signA));
        }
    }
}

// ---------- 2. .- (الطرح مع الإشارة) ----------
const char* dot_sub(const char* a, const char* b) {
    string sa(a), sb(b);
    // a - b = a + (-b)
    string neg_b = (sb[0] == '-') ? sb.substr(1) : "-" + sb;
    return dot_add(sa.c_str(), neg_b.c_str());
}

// ---------- 3. .* (Karatsuba مع الإشارة) ----------
static string karatsuba(const string& x, const string& y) {
    if (x == "0" || y == "0") return "0";
    if (x.size() < 10 || y.size() < 10) {
        string num1 = x, num2 = y;
        if (num1.size() < num2.size()) std::swap(num1, num2);
        reverse_s(num2);
        string total = "0";
        for (size_t i = 0; i < num2.size(); ++i) {
            int digit = c2i(num2[i]);
            if (digit == 0) continue;
            string temp = num1;
            reverse_s(temp);
            long long carry = 0;
            for (size_t j = 0; j < temp.size(); ++j) {
                long long prod = (long long)c2i(temp[j]) * digit + carry;
                temp[j] = i2c(prod % 10);
                carry = prod / 10;
            }
            if (carry) temp.push_back(i2c(carry));
            reverse_s(temp);
            temp.append(i, '0');
            total = simple_add(total, temp);
        }
        return total;
    }
    
    size_t n = std::max(x.size(), y.size());
    if (n % 2) n++; // نجعله زوجيًا
    string a = string(n - x.size(), '0') + x;
    string b = string(n - y.size(), '0') + y;
    
    size_t m = n / 2;
    string high1 = a.substr(0, m);
    string low1 = a.substr(m);
    string high2 = b.substr(0, m);
    string low2 = b.substr(m);
    
    string z0 = karatsuba(low1, low2);
    string z2 = karatsuba(high1, high2);
    
    string sum1 = simple_add(low1, high1);
    string sum2 = simple_add(low2, high2);
    string z1 = karatsuba(sum1, sum2);
    
    string middle = z1;
    middle = simple_sub(middle, z2);
    middle = simple_sub(middle, z0);
    
    string result = z2 + string(2 * (n - m), '0');
    result = simple_add(result, middle + string(n - m, '0'));
    result = simple_add(result, z0);
    
    return trim_zeros(result);
}

const char* dot_mul(const char* a, const char* b) {
    string sa(a), sb(b);
    int signRes = sign(sa) * sign(sb);
    string absRes = karatsuba(abs(sa), abs(sb));
    return return_string(apply_sign(absRes, signRes));
}

// ---------- 4. ./ (القسمة مع الإشارة) ----------
const char* dot_div(const char* a, const char* b) {
    string sa(a), sb(b);
    if (abs(sb) == "0") return return_string("Error");
    if (less_than(abs(sa), abs(sb))) return return_string("0");
    
    int signRes = sign(sa) * sign(sb);
    string dividend = abs(sa), divisor = abs(sb);
    string result;
    string current = "";
    
    for (char c : dividend) {
        current.push_back(c);
        current = trim_zeros(current);
        int count = 0;
        while (!less_than(current, divisor)) {
            string temp_div = divisor;
            int multiplier = 1;
            if (current.size() > temp_div.size()) {
                string shifted = temp_div + string(current.size() - temp_div.size(), '0');
                if (!less_than(current, shifted)) {
                    temp_div = shifted;
                    multiplier = (int)std::pow(10, current.size() - divisor.size());
                }
            }
            // طرح آمن باستخدام simple_sub (كلها موجبة)
            string diff = simple_sub(current, temp_div);
            current = diff;
            count += multiplier;
        }
        result.push_back(i2c(count));
    }
    result = trim_zeros(result);
    return return_string(apply_sign(result, signRes));
}

// ---------- 5. .% (باقي القسمة) ----------
const char* dot_mod(const char* a, const char* b) {
    string sa(a), sb(b);
    if (abs(sb) == "0") return return_string("Error");
    
    int signRes = sign(sa); // إشارة الباقي تتبع المقسوم
    string dividend = abs(sa), divisor = abs(sb);
    string current = "";
    for (char c : dividend) {
        current.push_back(c);
        current = trim_zeros(current);
        while (!less_than(current, divisor)) {
            string temp_div = divisor;
            if (current.size() > temp_div.size()) {
                string shifted = temp_div + string(current.size() - temp_div.size(), '0');
                if (!less_than(current, shifted)) temp_div = shifted;
            }
            current = simple_sub(current, temp_div);
        }
    }
    if (current.empty()) current = "0";
    return return_string(apply_sign(current, signRes));
}