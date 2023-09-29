   int testCases[] = {0, 1, 4,8, -1, 123, -123, 2147483647, -2147483648};
   int numTests = sizeof(testCases) / sizeof(testCases[0]);

    for (int i = 0; i < numTests; i++) {
       int num = testCases[i];
       int reversed = Reversbit(num);

       printf("Original number: %11d (0x%08X)\n", num, num);
       printf("Reversed number: %11d (0x%08X)\n", reversed, reversed);
       printf("--------------------------------------\n");
       }