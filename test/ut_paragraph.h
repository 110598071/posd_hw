#include "../src/paragraph.h"
#include "../src/article.h"
#include "../src/text.h"
#include "../src/list_item.h"

#include <gtest/gtest.h>
#include <stdexcept>

TEST(CaseParagraph, Creation) {
    EXPECT_NO_THROW(Paragraph p(2, "title"));
}

TEST(CaseParagrapgh, CreationWithLevelIsLesserThanOne) {
    EXPECT_THROW(Paragraph p1(0, "title");, std::out_of_range);
}

TEST(CasePragraph, CreationWithLevelIsGreaterThanSix) {
    EXPECT_THROW(Paragraph p2(7, "title");, std::out_of_range);
}

TEST(CaseParagrapgh, GetTextForTheCreationOfParagraphWhichJustHaveTitle) {
    Paragraph p(2, "title");
    ASSERT_EQ("## title\n", p.getText());
}

TEST(CaseParagraph, AddingTextToParagraph) {
    Paragraph p(2, "title");
    EXPECT_NO_THROW(p.add(new Text("text")));
}

TEST(CaseParagraph, AddingListItemToParagraph) {
    Paragraph p(2, "title");
    EXPECT_NO_THROW(p.add(new ListItem("text")));
}

TEST(CaseParagraph, AddingParagraphToParagraph) {
    Paragraph p(2, "title");
    EXPECT_NO_THROW(p.add(new Paragraph(3, "title2")));
}

TEST(CaseParagraph, AddingParagrpahWithGreaterLevelShouldThrowException) {
    Paragraph p(2, "title");
    Paragraph* p2 = new Paragraph(1, "title2");

    EXPECT_THROW(p.add(p2), std::out_of_range);
}

TEST(CaseParagraph, GetTextForAddingTextToParagraph) {
    Paragraph p(2, "title");
    p.add(new Text("text"));

    ASSERT_EQ("## title\ntext", p.getText());
}

TEST(CaseParagraph, GetTextForAddingListItemToParagraph) {
    Paragraph p(2, "title");
    p.add(new ListItem("text"));

    ASSERT_EQ("## title\n- text", p.getText());
}

TEST(CaseParagraph, GetTextForAddingParagraphToParagraph) {
    Paragraph p(2, "title");
    p.add(new Paragraph(3, "title2"));

    ASSERT_EQ("## title\n### title2\n", p.getText());
}

TEST(CaseParagraph, GetTextForAddingAllKindsOfArticleToParagraph) {
    Paragraph p(1, "title");
    p.add(new ListItem("list1"));
    p.add(new ListItem("list2"));
    p.add(new Text("text"));
    Paragraph* p2 = new Paragraph(2, "title2");
    p2->add(new ListItem("list3"));
    p2->add(new ListItem("list4"));
    p2->add(new Text("sub text"));
    p.add(p2);

    ASSERT_EQ("# title\n- list1\n- list2\ntext\n## title2\n- list3\n- list4\nsub text", p.getText());
}

TEST(CaseParagraph, ParagraphShouldBeArticle) {
    EXPECT_NO_THROW(Article* a = new Paragraph(2, "title"));
}