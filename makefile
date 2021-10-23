.PHONY: clean

TEST = test/ut_text.h test/ut_list_item.h test/ut_paragraph.h
SRC = src/text.h src/article.h src/list_item.h src/paragraph.h

bin/test: test/ut_main.cpp $(TEST) $(SRC) # 相依性檔案 -> [目標檔案(欲產生的檔案)]: [相依檔案]
	g++ -std=c++11 test/ut_main.cpp -o bin/ut_all -lgtest -lpthread

clean:
	rm -f bin/ut_all