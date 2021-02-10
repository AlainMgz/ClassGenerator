#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QGroupBox>
#include <QCheckBox>
#include <QDateEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QMessageBox>

class FenPrincipale : public QWidget
{
    Q_OBJECT

    public:
     FenPrincipale();

    private slots:
     void genererCode();

    private:
     QLineEdit *nom;
     QLineEdit *mere;
     QFormLayout *form1;
     QGroupBox *definitionGroupe;
     QGroupBox *optionsGroupe;
     QCheckBox *inclMulti;
     QCheckBox *constructeur;
     QCheckBox *destructeur;
     QVBoxLayout *layoutOption;
     QGroupBox *comGroupe;
     QLineEdit *auteur;
     QDateEdit *date;
     QTextEdit *role;
     QFormLayout *layoutCom;
     QHBoxLayout *layoutBtn;
     QPushButton *valider;
     QPushButton *annuler;
     QVBoxLayout *layoutPrincipale;



};

#endif // FENPRINCIPALE_H
