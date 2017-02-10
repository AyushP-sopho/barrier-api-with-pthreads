void main()
{
	Barrier b = new Barrier();
	int n;

	b.init(n);

	create n threads;
}

// Code to test ith thread
void BarTestTh()
{
	int thrId = getThreadId(); // made up syntax
	File outFile; // a file to store the output. Made-up syntax

	sleep(rand); // Sleeps for a random amount of time which simulates the thread doing some work

	outFile << "Thread before entering the barrier: " << thdId;

	b.barrier_point();

	outFile << "Thread after entering the barrier: " << thdId;

}