//---------------------------------------------------------------------------

#include <vcl.h>
#include <vector>
#include <sstream>
#include <map>
#include <utility>
#include <algorithm>

#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
using namespace std;
TForm1 *Form1;
const size=3;
static Level=1;

//������ ��� �������� �����:
static int dat[81];

//��������� ������ �� ��������� �������� � ��� ����������
struct sRow {
	int dat[9];     //������� ��������
	int correct[9]; //������ ��������
	int hidden[9];
};



//�������� ��������� ��� �������� ������� ������
struct sudokuGrid {
	sRow row[9];   //9 ����� �� 9 ��������� � ���������� ���������
};

//����� ���� ����� � �������� ������ ������ (swap_rows_small) ��� �����������
void swap_rows_small() {
		// Swap the two rows
		Randomize();
		int area = rand() % size ;
		int line1 = rand() % size ;
		//#��������� ���������� ������ � ��������� ������
		int N1 = area*size*size*size + line1*size*size ;
		//#����� 1 ������ ��� ������

		int line2 = rand() % size ;
		while (line1 == line2){line2 = rand() % size ;}

		int N2 = area*size*size*size + line2*size*size  ;
		//#����� 2 ������ ��� ������

		int temp, temp2;
		for (int i = 0; i<size*size; i++) {
			temp = dat[N1];
			dat[N1]=dat[N2];
			dat[N2]=temp;
			N1++; N2++;
		}

}

//����� ���� �������� � �������� ������ ������ (swap_colums_small) ��� �����������
void swap_colums_small() {
		// Swap the two rows
		Randomize();
		int area = rand() % size ;
		int col1 = rand() % size ;
		//#��������� ���������� ������ � ��������� ������
		int N1 = area*size + col1 ;
		//#����� 1 ������ ��� ������

		int col2 = rand() % size ;
		while (col1 == col2){col2 = rand() % size ;}

		int N2 = area*size + col2  ;
		//#����� 2 ������ ��� ������

		int temp, temp2;
		for (int i = 0; i<size*size; i++) {
			temp = dat[N1];
			dat[N1]=dat[N2];
			dat[N2]=temp;
			N1=N1+size*size; N2=N2+size*size;
		}

}


//���������� � ������ ������� ������� ������� � ������� ������ ������,
//�� ������� ������������, ��� �����������
void rearrange ()
{
	int cnt=20;
	for (int i = 0; i < cnt; i++) {
		swap_colums_small();
		swap_rows_small();
	}
}

static sudokuGrid out;

sudokuGrid initGrid() {

	//��������� ������� �������
	int ind=0;
	for (int i= 0; i < size*size; i++){
		int j;
		for (j = 0; j< size*size; j++){
			 dat[ind] = ((i*size + i/size + j) % (size*size))+ 1;
			 ind++;
		}
	}
	//"The base table is ready now!"

	//���������� ��������
	rearrange ();

	int i, j = 0;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			out.row[i].dat[j] = dat[9 * i + j];
			out.row[i].correct[j]=out.row[i].dat[j];
			if (out.row[i].dat[j] == 0) {
				out.row[i].hidden[j] = 1;
			}
			else {
				out.row[i].hidden[j] = 0;
			}
		}
	}



	//������ ����� �����, ������������ ���������� �������
		int cntHide;
		switch(Level)
  {
	case 1:
		cntHide =20;
		break;
	case 2:
		cntHide =40;
		break;
	case 3:
		cntHide =50;
		break;
  }

	for (int i = 0; i < cntHide; i++)
	{
		srand (time(NULL)*i);  // ����������������� ���������� ��������� �����
		int iSecret = rand() % 10 ;  //0...9
		int area = iSecret ;
		iSecret = rand() % 10 ;      //0...9
		int col1 = iSecret;
		out.row[area].hidden[col1]=1; //������ ������
	}
	return out;
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	out = initGrid();

//  ��������� �����
	 for (int i= 0; i < 9; i++){
	 int j;
		for (j = 0; j < 9; j++){
				bord[i][j] = new Sudoku(this);
				bord[i][j]->Parent = this;
				bord[i][j]->Top = 42 + ((j%9)*40);
				bord[i][j]->Left = 17 +((i%9)*40);
				bord[i][j]->setXY("cord" + IntToStr(i) + "_" + IntToStr(j));
				if (out.row[i].hidden[j]==1) {
					bord[i][j]->Text="";
				}else
					bord[i][j]->Text = IntToStr(out.row[i].dat[j]) ;

		}
	 }
	 TForm1::LockClick(this);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Rules1Click(TObject *Sender)
{
	ShowMessage("������ � ����������� � �������.������� ���� ������������ ����� ������� �������� 9x9, ���������� �� ������� �������� �� �������� � 3 ������. ����� �������, �� ������� ���� ������� �� 81 ������. � ��� ��� � ������ ���� ����� ��������� ����� (�� 1 �� 9), ���������� �����������. �� ������ ��������� ��������� ��������� ������ ������� �� 1 �� 9 ���, ����� � ������ ������, � ������ ������� � � ������ ����� �������� 3x3 ������ ����� ����������� �� ������ ���� ���.\
 ��������� ������ ������� �� ���������� ���������� ����������� ������ � �� �������, ������� ����� ��������� ��� � �������. ����� ������� �������� ����������: ������ ���� ���� �� ���� ������, ���� �������� ������ ���� �����. ��������� ����������� ����� ������ �� ��������� �����, �� ������ ����� ��������� ����.");
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Exit1Click(TObject *Sender)
{
	Application->Terminate();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::About1Click(TObject *Sender)
{
	ShowMessage("����������������: ���, 2018");
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TForm1::NewClick(TObject *Sender)
{
	out = initGrid();

	 for (int i = 0; i < 9; i++){
	 int j;
		for (j = 0; j < 9; j++){
				if (out.row[i].hidden[j]==1) {
					bord[i][j]->Text="";
				}else
					bord[i][j]->Text = IntToStr(out.row[i].dat[j]) ;

		}
	 }
	 TForm1::LockClick(this);


}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------


void __fastcall TForm1::LockClick(TObject *Sender)
{
	if (Lock->Caption == "�����������") {
		for (int i= 0; i < 9; i++){
			int j;
			for (j = 0; j < 9; j++){
				bord[i][j]->ReadOnly = false;
				bord[i][j]->Font->Color =  clBlue;
				if (bord[i][j]->Text != "") {
					bord[i][j]->ReadOnly = true;
					bord[i][j]->Font->Color =  clBlack;
				}
			}
		 }
	Lock->Caption = "�����������";
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ColourSet(){
	for (int i= 0; i < 9; i++){
			int j;
			for (j = 0; j < 9; j++){
				if(bord[i][j]->ReadOnly == true){
					bord[i][j]->Font->Color = clBlack;
				}
				else{
					bord[i][j]->Font->Color = clBlue;
				}

			}
		}
}

//---------------------------------------------------------------------------

void __fastcall TForm1::LvlEasy(TObject *Sender)
{
//������ ������� ������
		mnuEasy->Checked = True;
		mnuMiddle->Checked = False;
		mnuHard->Checked = False;
		Level = 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LvlMiddle(TObject *Sender)
{
//������� �������
		mnuEasy->Checked = False;
		mnuMiddle->Checked = True;
		mnuHard->Checked = False;
		Level = 2;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LvlHard(TObject *Sender)
{
		 //������� ������
		mnuEasy->Checked = False;
		mnuMiddle->Checked = False;
		mnuHard->Checked = True;
		Level = 3;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckValues(TObject *Sender)
{
//��������, ��������� ��������� ������������ ���� �����
	for (int i = 0; i < 9; i++){
			int j;
			for (j = 0; j < 9; j++)
			{

				if (bord[i][j]->Text != IntToStr(out.row[i].correct[j]) )
				{
					bord[i][j]->Font->Color = clRed;
				}
				else
				{
					if (bord[i][j]->ReadOnly == true) {
					   bord[i][j]->Font->Color = clBlack;
					}
					else
					{bord[i][j]->Font->Color = clBlue;}

				}
			}
		}
}
//---------------------------------------------------------------------------

