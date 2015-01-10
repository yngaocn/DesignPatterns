#ifndef TEMPLATEMETHOD_H
#define TEMPLATEMETHOD_H

namespace TemplateMethod
{
    class AbstractInstall
    {
    public:
        virtual void Step1()=0;
        virtual void Step2()=0;
        virtual void Step3()=0;
        virtual void Step4()=0;
        virtual void Step5()=0;
        void TemplateMethod();
    };

    class Install1 : public AbstractInstall
    {
    public:
        virtual void Step1();
        virtual void Step2();
        virtual void Step3();
        virtual void Step4();
        virtual void Step5();
    };

    class Install2 : public AbstractInstall
    {
    public:
        virtual void Step1();
        virtual void Step2();
        virtual void Step3();
        virtual void Step4();
        virtual void Step5();
    };

    void TestTemplateMethod();
}


#endif // TEMPLATEMETHOD_H
