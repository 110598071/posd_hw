#include "../src/list_item.h"
#include "../src/article.h"

#include <stdexcept>

TEST(CaseListItem, Creation) {
    EXPECT_NO_THROW(ListItem li("test"));
}

TEST(CaseListItem, GetText) {
    ListItem li("test");
    ASSERT_EQ("- test", li.getText());
}

TEST(CaseListItem, GetLevel) {
    ListItem li("test");
    ASSERT_EQ(0, li.getLevel());
}

TEST(CaseListItem, ListItemAddThrowException) {
    ListItem li("test");
    Article* a = new ListItem("k");

    EXPECT_THROW(li.add(a), std::out_of_range);
}

TEST(CaseListItem, ListItemShouldBeArticle) {
    EXPECT_NO_THROW(Article* a = new ListItem("k"));
}