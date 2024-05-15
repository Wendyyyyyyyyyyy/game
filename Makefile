FLAGS = -pedantic-errors -std=c++11 

home_page.o: home_page.cpp home_page.h
	g++ $(FLAGS) -c $<

card_bank.o: rules.cpp rules.h
	g++ $(FLAGS) -c $<

main.o: main.cpp home_page.h rules.h
	g++ $(FLAGS) -c $<

main: home_page.o rules.o main.o
	g++ $(FLAGS) $^ -o $@

clean:
	rm -f main *.o

tar:
	tar -czvf *.cpp *.h

.PHONY: clean tar
