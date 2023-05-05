#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCoreApplication>
#include <qevent.h>
#include <QKeyEvent>
#include<QRandomGenerator>
#include <QTableWidget>
#include<QMessageBox>
#include <QTime>
#include<QDebug>
#include <QStackedWidget>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),m_ptrStuSql(nullptr)
{
    ui->setupUi(this);
    m_ll.show();

    connect(&m_ll,&Login::sendLoginSuccess,this,[&]()
    {
        this->show();
    });
    ui->treeWidget->clear();
    ui->treeWidget->setColumnCount(1);
    QTreeWidgetItem*pf=new QTreeWidgetItem(ui->treeWidget,QStringList ("学生信息管理系统"));
    QTreeWidgetItem*p1=new QTreeWidgetItem(pf,QStringList ("学生管理"));
    QTreeWidgetItem*p2=new QTreeWidgetItem(pf,QStringList ("管理员管理"));
      ui->treeWidget->addTopLevelItem(pf);
      pf->addChild(p1);
      pf->addChild(p2);
      ui->treeWidget->expandAll();

      ui->stackedWidget->setCurrentIndex(1);


      m_ptrStuSql = stuSql::getinstance();
      m_ptrStuSql->init();
      m_lNames<<"苍雁露";
      m_lNames<<"世以彤";
      m_lNames<<"源朋 ";
      m_lNames<<"益明诚";
      m_lNames<<"房慕 ";
      m_lNames<<"道半青";
      m_lNames<<"謇语芹";
      m_lNames<<"储冷珍";
      m_lNames<<"孛昆纶";
      m_lNames<<"赧亦玉";
      m_lNames<<"邢南风";
      m_lNames<<"容语风";
      m_lNames<<"枝方方";
      m_lNames<<"沙歌韵";
      m_lNames<<"粟梓柔";
      m_lNames<<"冒姿 ";
      m_lNames<<"多晴波";
      m_lNames<<"聊芃芃";
      m_lNames<<"告辰钊";
      m_lNames<<"廉昂 ";
      m_lNames<<"刁幼菱";
      m_lNames<<"泣雨文";
      m_lNames<<"梁丘寄";
      m_lNames<<"仆嘉实";
      m_lNames<<"凤和蔼";
      m_lNames<<"鹿彦君";
      m_lNames<<"韦浩丽";
      m_lNames<<"卯新美";
      m_lNames<<"郑凡雁";
      m_lNames<<"德易真";
      m_lNames<<"己博裕";
      m_lNames<<"诗飞光";
      m_lNames<<"辜沛白";
      m_lNames<<"真悦远";
      m_lNames<<"乌苗 ";
      m_lNames<<"绪灵秀";
      m_lNames<<"眭岚彩";
      m_lNames<<"蔺凡雁";
      m_lNames<<"詹醉冬";
      m_lNames<<"公羊兰";
      m_lNames<<"叶新觉";
      m_lNames<<"苑运虹";
      m_lNames<<"栾小雯";
      m_lNames<<"茂雪儿";
      m_lNames<<"邴傲菡";
      m_lNames<<"须骞仕";
      m_lNames<<"秦甜 ";
      m_lNames<<"昝昊穹";
      m_lNames<<"区曼文";
      m_lNames<<"陶珺 ";
      m_lNames<<"钟离丹";
      m_lNames<<"殷淑然";
      m_lNames<<"褒桂帆";
      m_lNames<<"厍雅可";
      m_lNames<<"阎梦桐";
      m_lNames<<"象勇捷";
      m_lNames<<"钱丹翠";
      m_lNames<<"段浩皛";
      m_lNames<<"吾涵煦";
      m_lNames<<"彤敏叡";
      m_lNames<<"遇易真";
      m_lNames<<"山若星";
      m_lNames<<"竹又青";
      m_lNames<<"税乐和";
      m_lNames<<"丘书琴";
      m_lNames<<"姒晓山";
      m_lNames<<"登坚诚";
      m_lNames<<"单于明";
      m_lNames<<"郏英才";
      m_lNames<<"衅沛蓝";
      m_lNames<<"以茂才";
      m_lNames<<"受正 ";
      m_lNames<<"潘学林";
      m_lNames<<"危策 ";
      m_lNames<<"拱凡白";
      m_lNames<<"司寇英";
      m_lNames<<"瓮蒙 ";
      m_lNames<<"朴飞龙";
      m_lNames<<"展昊天";
      m_lNames<<"桥夏山";
      m_lNames<<"庚霁 ";
      m_lNames<<"费莫芷";
      m_lNames<<"疏亦凝";
      m_lNames<<"勾雅逸";
      m_lNames<<"相承弼";
      m_lNames<<"保康健";
      m_lNames<<"次量 ";
      m_lNames<<"水来 ";
      m_lNames<<"蒲曼寒";
      m_lNames<<"邶筠溪";
      m_lNames<<"悉秀媚";
      m_lNames<<"铎锐泽";
      m_lNames<<"买昌淼";
      m_lNames<<"巩文 ";
      m_lNames<<"丹任 ";
      m_lNames<<"章佳涆";
      m_lNames<<"丛妙之";
      m_lNames<<"寻弘新";
      m_lNames<<"终佑运";
      m_lNames<<"喜浩然";
      m_lNames<<"骑如波";
      m_lNames<<"帛雨筠";
      m_lNames<<"微生飞";
      m_lNames<<"常香萱";
      m_lNames<<"是宏远";
      m_lNames<<"化悦乐";
      m_lNames<<"员语诗";
      m_lNames<<"强益 ";
      m_lNames<<"边鸿雪";
      m_lNames<<"赖忆文";
      m_lNames<<"缪向荣";
      m_lNames<<"符建华";
      m_lNames<<"蓟善静";
      m_lNames<<"苌昊苍";
      m_lNames<<"萨鸥 ";
      m_lNames<<"蓬暄 ";
      m_lNames<<"庆子美";
      m_lNames<<"逄晨璐";
      m_lNames<<"菅暮雨";
      m_lNames<<"夕昕雨";
      m_lNames<<"东门梦";
      m_lNames<<"墨芷容";
      m_lNames<<"狄小萍";
      m_lNames<<"洛巧云";
      m_lNames<<"禹晴丽";
      m_lNames<<"风雅娴";
      m_lNames<<"时淑婉";
      m_lNames<<"隽宏壮";
      m_lNames<<"钊飞沉";
      m_lNames<<"圣耘志";
      m_lNames<<"邓云臻";
      m_lNames<<"咎韦 ";
      m_lNames<<"钟新月";
      m_lNames<<"璩俊贤";
      m_lNames<<"溥文漪";
      m_lNames<<"卢翰藻";
      m_lNames<<"匡玛 ";
      m_lNames<<"图门以";
      m_lNames<<"巢吟怀";
      m_lNames<<"盈友槐";
      m_lNames<<"麦昊然";
      m_lNames<<"袁怡 ";
      m_lNames<<"费如心";
      m_lNames<<"司马嘉";
      m_lNames<<"壬韵诗";
      m_lNames<<"檀海瑶";
      m_lNames<<"威河 ";
      m_lNames<<"戏高邈";
      m_lNames<<"辉芃 ";
      m_lNames<<"府慕梅";
      m_lNames<<"古山彤";
      m_lNames<<"乐正鸿";
      m_lNames<<"留嘉颖";
      m_lNames<<"藩诗柳";
      m_lNames<<"才竹韵";
      m_lNames<<"依希月";
      m_lNames<<"督鸿福";
      m_lNames<<"归平 ";
      m_lNames<<"义冰绿";
      m_lNames<<"党惜蕊";
      m_lNames<<"邹泽民";
      m_lNames<<"蔡乃欣";
      m_lNames<<"及雁山";
      m_lNames<<"席韵流";
      m_lNames<<"羊舌楠";
      m_lNames<<"蓝华月";
      m_lNames<<"戢嫔然";
      m_lNames<<"褚桀 ";
      m_lNames<<"贸夜梅";
      m_lNames<<"庄旭 ";
      m_lNames<<"北榆 ";
      m_lNames<<"甲承 ";
      m_lNames<<"臧润 ";
      m_lNames<<"缑寻桃";
      m_lNames<<"舒白梅";
      m_lNames<<"窦欣跃";
      m_lNames<<"潭梦晨";
      m_lNames<<"邝梓倩";
      m_lNames<<"奚晶 ";
      m_lNames<<"栋觅松";
      m_lNames<<"求欣荣";
      m_lNames<<"於惜寒";
      m_lNames<<"邵雨珍";
      m_lNames<<"貊夏彤";
      m_lNames<<"问舒扬";
      m_lNames<<"夔羽 ";
      m_lNames<<"佼赞 ";
      m_lNames<<"戚俊哲";
      m_lNames<<"旗慕晴";
      m_lNames<<"任森 ";
      m_lNames<<"速凝蝶";
      m_lNames<<"抗靖之";
      m_lNames<<"功美丽";
      m_lNames<<"延乐语";
      m_lNames<<"薛旭彬";
      m_lNames<<"张简嘉";
      m_lNames<<"宾绮思";
      m_lNames<<"笃琦珍";
      m_lNames<<"怀卿云";
      m_lNames<<"杭芷荷";
      m_lNames<<"辟夏旋";
      m_lNames<<"穆欣可";
      m_lNames<<"镜泰清";
      m_lNames<<"城若枫";
      m_lNames<<"腾凝然";
      m_lNames<<"郦忆然";
      m_lNames<<"支香彤";
      m_lNames<<"检书双";
      m_lNames<<"法麦冬";
      m_lNames<<"杜玲琳";
      m_lNames<<"力秋玉";
      m_lNames<<"似静槐";
      m_lNames<<"帅向薇";
      m_lNames<<"肖乐 ";
      m_lNames<<"塔从丹";
      m_lNames<<"苟依凝";
      m_lNames<<"景昂杰";
      m_lNames<<"谷易巧";
      m_lNames<<"何易文";
      m_lNames<<"羊齐敏";
      m_lNames<<"牧菀 ";
      m_lNames<<"韩白筠";
      m_lNames<<"倪书萱";
      m_lNames<<"鞠婉娜";
      m_lNames<<"贝鸿畅";
      m_lNames<<"锁丽华";
      m_lNames<<"太叔秋";
      m_lNames<<"后骊红";
      m_lNames<<"乐灵凡";
      m_lNames<<"汤杰秀";
      m_lNames<<"仲孙微";
      m_lNames<<"翟品韵";
      m_lNames<<"靖凝蕊";
      m_lNames<<"春古香";
      m_lNames<<"罕云溪";
      m_lNames<<"闵慕雁";
      m_lNames<<"鲍漪 ";
      m_lNames<<"花芬 ";
      m_lNames<<"宿芷珊";
      m_lNames<<"程文漪";
      m_lNames<<"逯阳飙";
      m_lNames<<"尔弘雅";
      m_lNames<<"陆兴为";
      m_lNames<<"僪修为";
      m_lNames<<"香飞双";
      m_lNames<<"勇汉 ";
      m_lNames<<"歧婉柔";
      m_lNames<<"错璞瑜";
      m_lNames<<"波夜香";
      m_lNames<<"鲜于宛";
      m_lNames<<"却采梦";
      m_lNames<<"泉访文";
      m_lNames<<"顾凡阳";
      m_lNames<<"焉嘉茂";
      m_lNames<<"蒯鸿畅";
      m_lNames<<"习司辰";
      m_lNames<<"无玉瑾";
      m_lNames<<"濯通 ";
      m_lNames<<"全翠丝";
      m_lNames<<"白诗桃";
      m_lNames<<"嵇银柳";
      m_lNames<<"竺寒 ";
      m_lNames<<"管佳晨";
      m_lNames<<"闻人卓";
      m_lNames<<"实慧秀";
      m_lNames<<"牢语心";
      m_lNames<<"抄梦凡";
      m_lNames<<"陀俏 ";
      m_lNames<<"牟章 ";
      m_lNames<<"巫马元";
      m_lNames<<"针小晨";
      m_lNames<<"翦冬易";
      m_lNames<<"康灵珊";
      m_lNames<<"善水风";
      m_lNames<<"栗弘阔";
      m_lNames<<"闳又松";
      m_lNames<<"百里心";
      m_lNames<<"汗慕卉";
      m_lNames<<"定景天";
      m_lNames<<"达平彤";
      m_lNames<<"宁子 ";
      m_lNames<<"屠生 ";
      m_lNames<<"御友 ";
      m_lNames<<"王以 ";
      m_lNames<<"鄂令 ";
      m_lNames<<"兴娟秀";
      m_lNames<<"郭夜南";
      m_lNames<<"贰驰轩";
      m_lNames<<"绳玮艺";
      m_lNames<<"赵烁 ";
      m_lNames<<"翠蕊珠";
      m_lNames<<"锐琬凝";
      m_lNames<<"霜念蕾";
      m_lNames<<"天湉湉";
      m_lNames<<"冀阳曦";
      m_lNames<<"贵承望";
      m_lNames<<"余开霁";
      m_lNames<<"巴晨风";
      m_lNames<<"晁睿诚";
      m_lNames<<"斐永元";
      m_lNames<<"莘夏青";
      m_lNames<<"将莹玉";
      m_lNames<<"折冷萱";
      m_lNames<<"马彭湃";
      m_lNames<<"曲未 ";
      m_lNames<<"阴多 ";
      m_lNames<<"季碧菡";
      m_lNames<<"郎德容";
      m_lNames<<"浑怜晴";
      m_lNames<<"盛凌春";
      m_lNames<<"桂白秋";
      m_lNames<<"温豪 ";
      m_lNames<<"务如仪";
      m_lNames<<"解香薇";
      m_lNames<<"邱兰月";
      m_lNames<<"铁宛曼";
      m_lNames<<"大正青";
      m_lNames<<"钞乐天";
      m_lNames<<"类兰梦";
      m_lNames<<"颛孙哲";
      m_lNames<<"萧芳蕙";
      m_lNames<<"袭飞荷";
      m_lNames<<"剧凝冬";
      m_lNames<<"玉音悦";
      m_lNames<<"宓好 ";
      m_lNames<<"瞿玟丽";
      m_lNames<<"姬涵菡";
      m_lNames<<"表鹏飞";
      m_lNames<<"祁婷美";
      m_lNames<<"有怀 ";
      m_lNames<<"刑骞 ";
      m_lNames<<"仍又晴";
      m_lNames<<"陈寄波";
      m_lNames<<"浦傲之";
      m_lNames<<"茆鸿文";
      m_lNames<<"彭理 ";
      m_lNames<<"李山灵";
      m_lNames<<"野宛秋";
      m_lNames<<"路女 ";
      m_lNames<<"愈恨寒";
      m_lNames<<"节冰海";
      m_lNames<<"僧星海";
      m_lNames<<"富高芬";
      m_lNames<<"麻凯泽";
      m_lNames<<"芒翠巧";
      m_lNames<<"伟民 ";
      m_lNames<<"祖半青";
      m_lNames<<"越俊美";
      m_lNames<<"佟亦巧";
      m_lNames<<"脱蓝 ";
      m_lNames<<"森冰 ";
      m_lNames<<"初静珊";
      m_lNames<<"友雪漫";
      m_lNames<<"虎念双";
      m_lNames<<"旁珂 ";
      m_lNames<<"修孤菱";
      m_lNames<<"钦和宜";
      m_lNames<<"乙忆彤";
      m_lNames<<"闭若淑";
      m_lNames<<"荀春桃";
      m_lNames<<"阿承基";
      m_lNames<<"允半蕾";
      m_lNames<<"劳芳懿";
      m_lNames<<"卜怀梦";
      m_lNames<<"本梦雨";
      m_lNames<<"别秀英";
      m_lNames<<"訾逸 ";
      m_lNames<<"望沛凝";
      m_lNames<<"堂智 ";
      m_lNames<<"孔香彤";
      updateTable();
}


MainWindow::~MainWindow()
{
    delete ui;
}
//F6刷新主题（未完成）
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_F6){
        QFile f;
        auto str = QCoreApplication::applicationDirPath();
        f.setFileName(str+"//"+"stuqss.css");
        f.open(QIODevice::ReadOnly);
        QString str1 = f.readAll();
        this->setStyleSheet(str1);
        m_ll.setStyleSheet(str1);
    }

}


void MainWindow::on_exitBtn_clicked()
{
    exit(0);
}
//数值仿真
void MainWindow::on_simBtn_clicked()
{
    QRandomGenerator g;
    QRandomGenerator c;
    g.seed(0); c.seed(0);
    QList<StuInfo> l;
//制作学生数据
    for(int i=0;i<m_lNames.size();i++){
        StuInfo info;
        auto grade =g.bounded(7,10);
        auto uiclass =g.bounded(1,8);
        info.name=m_lNames[i];
        if(i%3){
            info.age=16;
        }
        if(i%7){
            info.age=17;
        }
        if(i%2){
            info.age=18;
        }
        if(i==0){
            info.age=20;
        }
        info.grade=grade;
        info.uiclass=uiclass;
        info.studentid=i;
        info.phone=QString("17664550%1").arg(i);
        info.wechat=QString("tiantt%1").arg(i);
        l.append(info);

    }
     QTime   tmpTime;
        tmpTime.start();
       m_ptrStuSql->addStu(l);
        qDebug()<<"200条数据耗时："<<tmpTime.elapsed()<<"ms"<<endl;

        QTime   testTime;
        tmpTime.start();
        updateTable();
        qDebug()<<"更新数据耗时："<<testTime.elapsed()<<"ms"<<endl;


}

//添加按钮
void MainWindow::on_addBtn_clicked()
{
    m_dlgAddStu.setType(true);//设置为添加模式
    m_dlgAddStu.exec();
     updateTable();
}

void MainWindow::on_modBtn_clicked()
{
    StuInfo info;
        int i = ui->tableWidget->currentRow();
        if(i>=0)
        {
            info.id = ui->tableWidget->item(i,1)->text().toUInt();
            info.name = ui->tableWidget->item(i,2)->text();
            info.age = ui->tableWidget->item(i,3)->text().toUInt();
            info.grade = ui->tableWidget->item(i,4)->text().toUInt();
            info.uiclass = ui->tableWidget->item(i,5)->text().toUInt();
            info.studentid = ui->tableWidget->item(i,6)->text().toUInt();
            info.phone = ui->tableWidget->item(i,7)->text();
            info.wechat = ui->tableWidget->item(i,8)->text();
            m_dlgAddStu.setType(false,info);//设置为编辑模式
            m_dlgAddStu.exec();
        }
        updateTable();
}
//删除按钮
void MainWindow::on_delBtn_clicked()
{
    int i =ui->tableWidget->currentRow();
    if(i>=0){
        int id = ui->tableWidget->item(i,1)->text().toUInt();
        m_ptrStuSql->delStu(id);
        updateTable();
        QMessageBox::information(nullptr,"信息","删除成功");
    }
    else
    {
        QMessageBox::information(nullptr,"信息","失败");
    }
}
//清空按钮
void MainWindow::on_clcBtn_clicked()
{
    m_ptrStuSql->clearStuTable();
     updateTable();
}
//更新函数
void MainWindow::updateTable()
{
    //代码添加表头
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(9);
    QStringList l;
   l<<"序号"<<"ID"<<"姓名"<<"年龄"<<"年级"<<"班级"<<"学号"<<"电话"<<"微信";
    ui->tableWidget->setHorizontalHeaderLabels(l);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//只选中行
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    auto cnt=m_ptrStuSql->getStuCnt();//得到学生总数量
    ui->lbCnt->setText(QString("学生数量总数：%1").arg(cnt));
   QList<StuInfo>lStudent= m_ptrStuSql->getPageStu(0,cnt);
    ui->tableWidget->setRowCount(cnt);
    for(int i=0;i<lStudent.size();i++){
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(i)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(lStudent[i].id)));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(lStudent[i].name));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(lStudent[i].age)));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(lStudent[i].grade)));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(QString::number(lStudent[i].uiclass)));
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(QString::number(lStudent[i].studentid)));
        ui->tableWidget->setItem(i,7,new QTableWidgetItem(lStudent[i].phone));
        ui->tableWidget->setItem(i,8,new QTableWidgetItem(lStudent[i].wechat));

    }
}

void MainWindow::on_serBtn_clicked()
{
    QString strFilter =ui->leSearch->text();//输入搜索框的文本
    //获取要筛选的学生信息
        if(strFilter.isEmpty())
        {
            QMessageBox::information(nullptr,"警告","请输入内容！");
            updateTable();
            return;
        }

    //代码添加表头
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(9);
    QStringList l;
   l<<"序号"<<"ID"<<"姓名"<<"年龄"<<"年级"<<"班级"<<"学号"<<"电话"<<"微信";
    ui->tableWidget->setHorizontalHeaderLabels(l);

    auto cnt=m_ptrStuSql->getStuCnt();//得到学生总数量
    ui->lbCnt->setText(QString("学生数量总数：%1").arg(cnt));
   QList<StuInfo>lStudent= m_ptrStuSql->getPageStu(0,cnt);


   int index =0;

        for(int i=0;i<lStudent.size();i++)
        {
            if(!lStudent[i].name.contains(strFilter))
            {
                continue;//循环对比学生信息时候与筛选的一致  不一致不往下执行 返回循环
            }


        ui->tableWidget->setRowCount(cnt);
        ui->tableWidget->setItem(index,0,new QTableWidgetItem(QString::number(index)));
        ui->tableWidget->setItem(index,1,new QTableWidgetItem(QString::number(lStudent[i].id)));
        ui->tableWidget->setItem(index,2,new QTableWidgetItem(lStudent[i].name));
        ui->tableWidget->setItem(index,3,new QTableWidgetItem(QString::number(lStudent[i].age)));
        ui->tableWidget->setItem(index,4,new QTableWidgetItem(QString::number(lStudent[i].grade)));
        ui->tableWidget->setItem(index,5,new QTableWidgetItem(QString::number(lStudent[i].uiclass)));
        ui->tableWidget->setItem(index,6,new QTableWidgetItem(QString::number(lStudent[i].studentid)));
        ui->tableWidget->setItem(index,7,new QTableWidgetItem(lStudent[i].phone));
        ui->tableWidget->setItem(index,8,new QTableWidgetItem(lStudent[i].wechat));
        index ++;

}

ui->tableWidget->setRowCount(index);
ui->lbCnt->setText(QString("搜索人数：%1").arg(index));
if(index == 0 ){
    QMessageBox::information(nullptr,"警告","查无此人！");
    updateTable();
    return;
}


}
