#include "FenPrincipale.h"
#include "fencodegenere.h"
#include <string>
#include <iostream>
using namespace std;

FenPrincipale::FenPrincipale()
{

    // GROUPE : Definition
    nom = new QLineEdit;
    mere = new QLineEdit;

    form1 = new QFormLayout;
    form1->addRow("Nom : ", nom);
    form1->addRow("Classe mère : ", mere);

    definitionGroupe = new QGroupBox("Définition de la classe");
    definitionGroupe->setLayout(form1);

    // GROUPE : Options
    optionsGroupe = new QGroupBox("Options");
    inclMulti = new QCheckBox("Protéger le header contre les inclusions multiples");
    inclMulti->setChecked(true);
    constructeur = new QCheckBox("Générer un contructeur par défaut");
    constructeur->setChecked(true);
    destructeur = new QCheckBox("Générer un destructeur");

    layoutOption = new QVBoxLayout;
    layoutOption->addWidget(inclMulti);
    layoutOption->addWidget(constructeur);
    layoutOption->addWidget(destructeur);

    optionsGroupe->setLayout(layoutOption);

    // GROUPE : Commentaires

    comGroupe = new QGroupBox("Ajouter des commentaires");
    comGroupe->setCheckable(true);
    comGroupe->setChecked(true);

    auteur = new QLineEdit;
    date = new QDateEdit;
    date->setDate(QDate::currentDate());
    role = new QTextEdit;

    layoutCom = new QFormLayout;
    layoutCom->addRow("Auteur : ", auteur);
    layoutCom->addRow("Date : ", date);
    layoutCom->addRow("Rôle : ", role);
    if(comGroupe->isChecked() == true)
    {
        comGroupe->setLayout(layoutCom);
    }



    // Boutons du bas
    layoutBtn = new QHBoxLayout;
    valider = new QPushButton("Générer ! ");
    annuler = new QPushButton("Annuler");
    layoutBtn->addWidget(valider);
    layoutBtn->addWidget(annuler);

    QObject::connect(annuler, SIGNAL(clicked()), qApp, SLOT(quit()));
    QObject::connect(valider, SIGNAL(clicked()), this, SLOT(genererCode()));

    layoutPrincipale = new QVBoxLayout;
    layoutPrincipale->addWidget(definitionGroupe);
    layoutPrincipale->addWidget(optionsGroupe);
    layoutPrincipale->addWidget(comGroupe);
    layoutPrincipale->addLayout(layoutBtn);



    setLayout(layoutPrincipale);
    setWindowTitle("Class Generator");
    setWindowIcon(QIcon("images/icone.png"));
    resize(400, 500);
}

void FenPrincipale::genererCode()
{
    if(nom->text().isEmpty())
    {
        QMessageBox::critical(this, "Error", "Vous devez renseigner le nom de votre classe");
        return;
    }
    QString code;
    if(comGroupe->isChecked())
    {
        code += "/* \nAuteur : " + auteur->text() + "\n";
        code += "Date de création : " + date->text() + "\n";
        code += "Rôle de la classe : " + role->toPlainText() + "\n*/\n";
    }
    if(inclMulti->isChecked())
    {
        code += "#ifndef HEADER_" + nom->text().toUpper() + "\n";
        code += "#define HEADER_" + nom->text().toUpper() + "\n\n\n";
    }

    code += "class " + nom->text();

    if(!mere->text().isEmpty())
    {
        code += " : public " + mere->text();
    }

    code += "\n{\n   public:\n";
    if(constructeur->isChecked())
    {
        code += "    " + nom->text() + "();\n";
    }
    if(destructeur->isChecked())
    {
        code += "    ~" + nom->text() + "();\n";
    }
    code += "\n   protected:\n\n   private:\n}\n\n";
    if(inclMulti->isChecked())
    {
        code += "#endif";
    }


    FenCodeGenere *fenetreCode = new FenCodeGenere(code, this);
    fenetreCode->exec();
}
