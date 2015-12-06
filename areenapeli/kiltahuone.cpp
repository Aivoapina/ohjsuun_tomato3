#include "kiltahuone.h"
#include "ui_kiltahuone.h"
#include "qdebug.h"


kiltahuone::kiltahuone(ArenaTeam *tiimi, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::kiltahuone)
{
    ui->setupUi(this);
    selection_ = nullptr;
    tiimi_ = tiimi;
    model_ = new kiltaModel();
    model_->makePleb();
    ui->listView->setModel(model_);
    connect(ui->listView->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(view_clicked()));
    setUpdatesEnabled(true);
    ui->listView->setUpdatesEnabled(true);
}

kiltahuone::~kiltahuone()
{
    delete ui;
}

void kiltahuone::on_osta_clicked()
{

    if( selection_ == nullptr ){
        return;
    }
    else{
        if( tiimi_->getPlebs().size() >= 4){
            return;
        }
        if( tiimi_->get_raha() >= selection_->r_hinta()){
            tiimi_->buyNewMember(selection_);
            model_->removeRow(ui->listView->currentIndex().row());
            if(model_->rowCount() != 0){
                std::shared_ptr<ArenaMember> selection(new ArenaMember(ui->listView->selectionModel()->currentIndex().data(Qt::UserRole +1 ).toStringList()));
                selection_ = selection;
            }
            else{
                selection_ = nullptr;
            }
            emit pleb_ostettu();
        }
        else{
            return;
        }
    }
}

void kiltahuone::view_clicked()
{
    if(model_->rowCount() == 1 ){
        for(auto i: ui->selectionWidget->children()){
            delete i;
        }
        return;
    }
    std::shared_ptr<ArenaMember> selection(new ArenaMember(ui->listView->selectionModel()->currentIndex().data(Qt::UserRole +1 ).toStringList()));
    selection_ = selection;
    for(auto i: ui->selectionWidget->children()){
        delete i;
    }
    plebRuutu *w = new plebRuutu(selection_, ui->selectionWidget);
    w->show();
}
