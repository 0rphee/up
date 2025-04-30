TARGET = ex-p2
FLEX_SRC = ex-p2.l
CXX = c++
CXXFLAGS = -std=c++11 -Wall -Wextra
LEX_OUTPUT = lex.yy.cc
ZIP_FILE = examen.zip

all: $(TARGET)

$(TARGET): $(LEX_OUTPUT)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(LEX_OUTPUT)

$(LEX_OUTPUT): $(FLEX_SRC)
	flex -o $(LEX_OUTPUT) $(FLEX_SRC)

run: $(TARGET)
	./$(TARGET) input.txt

clean:
	rm -f $(LEX_OUTPUT) $(TARGET) $(ZIP_FILE)

zip:
	$(MAKE) run
	rm $(TARGET)
	zip -r $(ZIP_FILE) . -x $(ZIP_FILE) -x "*.DS_Store"
