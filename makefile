all:
	g++ -std=c++17 main.cpp -o ac_lag_fix

clean:
	$(RM) ac_lag_fix