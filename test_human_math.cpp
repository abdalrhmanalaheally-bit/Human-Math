#include "human_math.h"
#include <iostream>
#include <iomanip>
#include <cstring>

// Helper function to display results nicely
void print_test(const char* operation, const char* result) {
    std::cout << std::left << std::setw(50) << operation << " = " << result << "\n";
}

int main() {
    std::cout << "\n╔════════════════════════════════════════════════════════════╗\n";
    std::cout << "║         HUMAN MATH LIBRARY - COMPREHENSIVE TESTS           ║\n";
    std::cout << "╚════════════════════════════════════════════════════════════╝\n\n";

    // Test 1: Basic Addition
    std::cout << "━━━━━ TEST 1: ADDITION ━━━━━\n";
    const char* add1 = dot_add("99999999999999999999", "1");
    print_test("99999999999999999999 + 1", add1);
    
    const char* add2 = dot_add("123456789", "987654321");
    print_test("123456789 + 987654321", add2);
    
    const char* add3 = dot_add("-100", "150");
    print_test("-100 + 150", add3);
    free_string((char*)add1); free_string((char*)add2); free_string((char*)add3);

    // Test 2: Subtraction
    std::cout << "\n━━━━━ TEST 2: SUBTRACTION ━━━━━\n";
    const char* sub1 = dot_sub("1000000000", "1");
    print_test("1000000000 - 1", sub1);
    
    const char* sub2 = dot_sub("50", "100");
    print_test("50 - 100", sub2);
    
    const char* sub3 = dot_sub("-200", "-50");
    print_test("-200 - (-50)", sub3);
    free_string((char*)sub1); free_string((char*)sub2); free_string((char*)sub3);

    // Test 3: Multiplication (Karatsuba Algorithm)
    std::cout << "\n━━━━━ TEST 3: MULTIPLICATION (Karatsuba Algorithm) ━━━━━\n";
    const char* mul1 = dot_mul("123456789", "987654321");
    print_test("123456789 * 987654321", mul1);
    
    const char* mul2 = dot_mul("999999999999", "999999999999");
    print_test("999999999999 * 999999999999", mul2);
    
    const char* mul3 = dot_mul("-5", "20");
    print_test("-5 * 20", mul3);
    free_string((char*)mul1); free_string((char*)mul2); free_string((char*)mul3);

    // Test 4: Division
    std::cout << "\n━━━━━ TEST 4: DIVISION ━━━━━\n";
    const char* div1 = dot_div("100", "10");
    print_test("100 / 10", div1);
    
    const char* div2 = dot_div("1234567890", "123");
    print_test("1234567890 / 123", div2);
    
    const char* div3 = dot_div("-100", "7");
    print_test("-100 / 7", div3);
    free_string((char*)div1); free_string((char*)div2); free_string((char*)div3);

    // Test 5: Modulo (Remainder)
    std::cout << "\n━━━━━ TEST 5: MODULO (Remainder) ━━━━━\n";
    const char* mod1 = dot_mod("100", "7");
    print_test("100 mod 7", mod1);
    
    const char* mod2 = dot_mod("1000000007", "1000000007");
    print_test("1000000007 mod 1000000007", mod2);
    
    const char* mod3 = dot_mod("123456789", "100");
    print_test("123456789 mod 100", mod3);
    free_string((char*)mod1); free_string((char*)mod2); free_string((char*)mod3);

    // Test 6: Complex Expression - Simulate ((a+b-c)*d / e) mod m
    std::cout << "\n━━━━━ TEST 6: COMPLEX EXPRESSION ━━━━━\n";
    std::cout << "Expression: ((12345 + 67890 - 5000) * 100 / 5) mod 1000\n\n";
    
    const char* step1 = dot_add("12345", "67890");
    std::cout << "Step 1 (12345 + 67890) = " << step1 << "\n";
    
    const char* step2 = dot_sub(step1, "5000");
    std::cout << "Step 2 (80235 - 5000) = " << step2 << "\n";
    
    const char* step3 = dot_mul(step2, "100");
    std::cout << "Step 3 (75235 * 100) = " << step3 << "\n";
    
    const char* step4 = dot_div(step3, "5");
    std::cout << "Step 4 (7523500 / 5) = " << step4 << "\n";
    
    const char* step5 = dot_mod(step4, "1000");
    std::cout << "Step 5 (1504700 mod 1000) = " << step5 << "\n";
    
    free_string((char*)step1); free_string((char*)step2); free_string((char*)step3);
    free_string((char*)step4); free_string((char*)step5);

    // Test 7: Diffie-Hellman Style Test (Modular Exponentiation)
    std::cout << "\n━━━━━ TEST 7: MODULAR ARITHMETIC TEST ━━━━━\n";
    std::cout << "Computing: 5^6 mod 23\n";
    
    const char* base = "5";
    const char* p = "23";
    
    const char* temp1 = dot_mul("5", "5");      // 5^2
    std::cout << "5^2 = " << temp1 << "\n";
    
    const char* temp2 = dot_mul(temp1, "5");    // 5^3
    std::cout << "5^3 = " << temp2 << "\n";
    
    const char* temp3 = dot_mul(temp2, temp2);  // 5^6 (since 5^3 * 5^3 = 5^6)
    std::cout << "5^6 = " << temp3 << "\n";
    
    const char* result = dot_mod(temp3, p);
    std::cout << "5^6 mod 23 = " << result << " (Expected: 8)\n";
    
    free_string((char*)temp1); free_string((char*)temp2); 
    free_string((char*)temp3); free_string((char*)result);

    // Test 8: Edge Cases
    std::cout << "\n━━━━━ TEST 8: EDGE CASES ━━━━━\n";
    const char* edge1 = dot_add("0", "0");
    print_test("0 + 0", edge1);
    
    const char* edge2 = dot_mul("0", "999999999");
    print_test("0 * 999999999", edge2);
    
    const char* edge3 = dot_sub("100", "100");
    print_test("100 - 100", edge3);
    
    free_string((char*)edge1); free_string((char*)edge2); free_string((char*)edge3);

    std::cout << "\n╔════════════════════════════════════════════════════════════╗\n";
    std::cout << "║                    ALL TESTS COMPLETED!                    ║\n";
    std::cout << "╚════════════════════════════════════════════════════════════╝\n\n";

    return 0;
}
