#include "brtc_webjs.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QtScript/QScriptEngine>

BRTC_WEBJS::BRTC_WEBJS(QObject *parent) : QObject(parent)
{

}

void BRTC_WEBJS::BRTC_Webjs(QString id,QString room){
//    QFile file("baidu.rtc.sdk.js");

//    if (!file.open(QIODevice::ReadOnly)) {
//        //abortOperation();
//        qDebug()<<" file(baidu.rtc.sdk.js) can not open!";
//        return;
//    }else{
//        qDebug()<<" file baidu.rtc.sdk.js is open!";
//    }

//    QTextStream in(&file);
//    in.setCodec("UTF-8");

//    QString script = in.readAll();
//    qDebug()<<script;
//    file.close();
//    //qDebug()<<display->text().toDouble();

//    QScriptEngine interpreter;
//    QScriptValue operand(&interpreter, display->text().toDouble());
//    interpreter.globalObject().setProperty("x", operand);//这里设置全局属性x，在js中就可以调用到
//    qDebug()<<interpreter.globalObject().property("x").toNumber();


//    QString fileName = "helloworld.qs";//保存错误信息，没其他用处
//    QScriptValueList args1;
//    args1<<operand;
//    QScriptValue result = interpreter.evaluate(script,fileName);
//    qDebug()<<result.toNumber()<<result.toString();
//    qDebug()<<interpreter.globalObject().property("x").toNumber();
//    QScriptValue test=result.call(QScriptValue(),args1);


//    QScriptEngine myEngine;
//    QScriptValue fun = myEngine.evaluate("(function(a, b) { return a + b; })");
//    QScriptValueList args;
//    args <<1<< 2;
//    QScriptValue threeAgain = fun.call(QScriptValue(), args);
//    qDebug()<<threeAgain.toNumber();
//    qDebug()<<test.toNumber();
//    if (!result.isNumber()) {
//        return;
//    }

}
