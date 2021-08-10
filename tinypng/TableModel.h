#pragma once

#include <QAbstractTableModel>


typedef struct TableModelRow {
	QString root;
	QString path;
	int size;
	int thin_size; //压缩后的大小
	int status;
}_TableModelRow;

class TableModel : public QAbstractTableModel
{
	Q_OBJECT

public:
	TableModel(QObject* parent);
	~TableModel();
	virtual int rowCount(const QModelIndex & = QModelIndex()) const override;
	virtual int columnCount(const QModelIndex & = QModelIndex()) const override;
	virtual QVariant data(const QModelIndex& index, int role) const override;
	QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
	void removeRow(int row, const QModelIndex& index = QModelIndex());
	void removeAll();
	TableModelRow getRow(int row);
	void replaceRow(int row, TableModelRow item);
	void updateStatus(int row, int status);
private:
	QList<TableModelRow> _data = QList<TableModelRow>();

public slots:
	void addRow(QList<TableModelRow>);
	void addRow(TableModelRow);
signals:
	void addRowSignal(TableModelRow);
};
