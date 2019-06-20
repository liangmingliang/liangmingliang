
/*
 * run in aarch64
 */

void test_asm()
{
    asm volatile ("nop\n");
	int a = 1;
    asm volatile ("nop\n");
	int b = 2;
    asm volatile ("nop\n");
	int c = 0;
    asm volatile ("nop\n");
	c = a + b;
    asm volatile ("nop\n");


	int aa = 3;
	int bb = 4;
	int cc = 0;


	printf("aa = %d\n", aa);
	printf("bb = %d\n", bb);
	printf("cc = %d\n", cc);

}

main()
{
    int a = 15;
	int b = 26;
	int c = 0;

	/* x2 : a
	 * x1 : b
     * x0 : c
	 */ 
	__asm__ __volatile__(
	    "add x0, x1, x2\n"
	    "add x0, x0, 1 \n"
	    "add x1, x1, 1 \n"
	    "add x2, x2, 1 \n"
		:"+r"(a),"+r"(b), "+r"(c)
	);

	printf("a is %d\n", a);
	printf("b is %d\n", b);
	printf("c is %d\n", c);
}
