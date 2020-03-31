#include "systemc.h"
#include "CPU_1.cpp"
#include "CPU_2.cpp"


/* Kolejka FIFO */
SC_MODULE(queue) {

	sc_fifo<int> Queue;

	SC_CTOR(queue) {
		sc_fifo<int> Queue(6);
	}
};

/* Top Level Function - funkcja main */
int sc_main(int argc, char* argv[]) {

	sc_signal<sc_uint<8>, SC_MANY_WRITERS> diodes;
	sc_signal<sc_uint<8>, SC_MANY_WRITERS> switches;
	sc_signal<sc_uint<8>, SC_MANY_WRITERS> hex[6];

	queue q("queue");

	cpu1 procesor_1("cpu1");
	procesor_1.output(q.Queue);
	procesor_1.diodes(diodes);
	procesor_1.switches(switches);

	for (int i = 0; i < 6; i++)
		procesor_1.hexes[i](hex[i]);

	cpu2 procesor_2("cpu2");
	procesor_2.input(q.Queue);
	for (int i = 0; i < 6; i++)
		procesor_2.hexes[i](hex[i]);

	sc_start();

	cout << endl << endl;
	return(0);
}