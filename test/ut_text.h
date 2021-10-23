#include "../src/text.h"
#include "../src/article.h"

#include <stdexcept>

TEST(CaseText, Creation) {
    EXPECT_NO_THROW(Text t("test"));
}

TEST(CaseText, GetText) {
    Text t("test");
    ASSERT_EQ("test", t.getText());
}

TEST(CaseText, GetLevel) {
    Text t("test");
    ASSERT_EQ(0, t.getLevel());
}

TEST(CaseText, TextAddThrowException) {
    Text t("test");
    Article* a = new Text("k");

    EXPECT_THROW(t.add(a), std::out_of_range);
}

TEST(CaseText, TextShouldBeArticle) {
    EXPECT_NO_THROW(Article* a = new Text("k"));
}