all: ACMCoffeeMachine

ACMCoffeeMachine: build/Main.o build/Node.o build/CommandHandler.o build/CoffeeMachineTreeMaker.o build/ConfigurationChecker.o build/CoffeeMachine.o build/Feature.o build/Independent.o build/Dependent.o build/Mandatory.o build/Optional.o build/Alternative.o build/Or.o build/Tools.o build/BadException.o
	@echo "##Linking..."
	g++ build/Main.o build/Node.o build/CommandHandler.o build/CoffeeMachineTreeMaker.o build/ConfigurationChecker.o build/CoffeeMachine.o build/Feature.o build/Independent.o build/Dependent.o build/Mandatory.o build/Optional.o build/Alternative.o build/Or.o build/Tools.o build/BadException.o -o bin/ACMCoffeeMachine
	@echo "##You can find object files in ./build directory."
	@echo "##Exectuable file is in ./bin ."




build/Main.o: src/Main.cpp 
	g++ -c src/Main.cpp -o build/Main.o

build/BadException.o: src/BadException.cpp include/BadException.h
	g++ -c src/BadException.cpp -o build/BadException.o

build/CommandHandler.o: src/CommandHandler.cpp include/CommandHandler.h
	g++ -c src/CommandHandler.cpp -o build/CommandHandler.o

build/CoffeeMachineTreeMaker.o: src/CoffeeMachineTreeMaker.cpp include/CoffeeMachineTreeMaker.h
	g++ -c src/CoffeeMachineTreeMaker.cpp -o build/CoffeeMachineTreeMaker.o

build/ConfigurationChecker.o: src/ConfigurationChecker.cpp include/ConfigurationChecker.h
	g++ -c src/ConfigurationChecker.cpp -o build/ConfigurationChecker.o

build/Node.o: src/Node.cpp include/Node.h
	g++ -c src/Node.cpp -o build/Node.o

build/CoffeeMachine.o: src/CoffeeMachine.cpp include/CoffeeMachine.h src/Node.cpp include/Node.h
	g++ -c src/CoffeeMachine.cpp -o build/CoffeeMachine.o

build/Feature.o: src/Feature.cpp include/Feature.h src/Node.cpp include/Node.h
	g++ -c src/Feature.cpp -o build/Feature.o

build/Independent.o: src/Independent.cpp include/Independent.h src/Feature.cpp include/Feature.h
	g++ -c src/Independent.cpp -o build/Independent.o

build/Dependent.o: src/Dependent.cpp include/Dependent.h src/Feature.cpp include/Feature.h
	g++ -c src/Dependent.cpp -o build/Dependent.o

build/Mandatory.o: src/Mandatory.cpp include/Mandatory.h src/Independent.cpp include/Independent.h
	g++ -c src/Mandatory.cpp -o build/Mandatory.o

build/Optional.o: src/Optional.cpp include/Optional.h src/Independent.cpp include/Independent.h
	g++ -c src/Optional.cpp -o build/Optional.o

build/Or.o: src/Or.cpp include/Or.h src/Dependent.cpp include/Dependent.h
	g++ -c src/Or.cpp -o build/Or.o

build/Alternative.o: src/Alternative.cpp include/Alternative.h src/Dependent.cpp include/Dependent.h
	g++ -c src/Alternative.cpp -o build/Alternative.o

build/Tools.o: src/Tools.cpp include/Tools.h
	g++ -c src/Tools.cpp -o build/Tools.o



clean:
	@echo "##Deleteing obeject files and exectuable file..."
	rm build/*.o bin/ACMCoffeeMachine
