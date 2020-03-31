#include <systemc.h>

using namespace std;

SC_MODULE(cpu2)
{
	sc_fifo_in<int> input;
	sc_inout<sc_uint<8>> hexes[6];

	void task1() {
		
		while (1) {
			sc_uint<8> progNo = input.read();
			if (progNo == 2) {
				cout << "Task 1 - 02. PDset" << endl;
				hexes[5].write(0);
				hexes[4].write(2);
				hexes[3].write('.');
				hexes[2].write('S');
				hexes[1].write('E');
				hexes[0].write('T');
			}
		}
		wait(10, SC_MS);
	}

	SC_CTOR(cpu2) {
		SC_THREAD(task1);
	}
};