#include <QtTest>
#include "C:/others/code/project/1325/func.h"
//"C:\others\code\проект на c++\13 25\func.h"
// add necessary includes here

class UnitTest : public QObject
{
    Q_OBJECT

public:
    UnitTest();
    ~UnitTest();

private slots:
    void test_case1();
    void test_case2();
    void test_case3();
    void test_case4();
    void test_case5();

};

UnitTest::UnitTest()
{

}

UnitTest::~UnitTest()
{

}

void UnitTest::test_case1()
{
    QString login = "admin";
    QString password = "qwerty";
    QString socket_id = "880";

    QCOMPARE(authorization(login,password,socket_id),"Welcome! Admin");
}

void UnitTest::test_case2()
{
    QString login = "admin";
    QString password = "qwerty";
    QString email = "456@gmail.com";
    QString role = "s";
    QString surname = "klim";
    QString name = "serega";

    QCOMPARE(reg(login,password,email,role,surname,name),"This username is already used");
}

void UnitTest::test_case3()
{
    QString login = "mateyka";
    QString task_num = "1";
    QString m1_mnoj = "4";
    QString task_ans_t = "0110";

    QCOMPARE(check_task_answer(login,task_num,m1_mnoj,task_ans_t),"+1");
}

void UnitTest::test_case4()
{
    QString login = "admin";

    QCOMPARE(exit(login),"exit ok");
}

void UnitTest::test_case5()
{
    QString login = "admin";
    QCOMPARE(get_stat(login),"admin 1.0 2.0 3.0 4.0 5.0");
}

QTEST_APPLESS_MAIN(UnitTest)

#include "tst_unittest.moc"
