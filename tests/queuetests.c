#include <criterion/criterion.h>

#include "../src/myqueue.h"

queue *q = NULL;

void suitesetup(void)
{
	q = q_create(5);
}

void suiteteardown(void)
{
	q_destroy(q);
}

TestSuite(queuetests, .init=suitesetup, .fini=suiteteardown);

Test(queuetests, create)
{
	//queue* q = q_create(5);
	cr_expect(q != NULL, "q_create should return not NULL.");
}

Test(queuetests, add)
{
	//queue* q = q_create(5);
	cr_expect(q_enqueue(q, 1), "expected enqueue to succeed.");
	cr_expect(q_enqueue(q, 2), "expected enqueue to succeed.");
	cr_expect(q_enqueue(q, 3), "expected enqueue to succeed.");
	cr_expect(q_enqueue(q, 4), "expected enqueue to succeed.");
	cr_expect(q_enqueue(q, 5), "expected enqueue to succeed.");
	cr_expect(q_enqueue(q, 6) == false, "expected enqueue to fail.");
}
