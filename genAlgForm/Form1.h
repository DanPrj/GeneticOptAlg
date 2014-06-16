#pragma once
#include "Population.h"

namespace liveGameClasses {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
		
		Graphics  ^gr;
		BufferedGraphicsContext ^st;
	private: System::Windows::Forms::Button^  button1;

			 BufferedGraphics ^buff;

	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::TrackBar^  trackBar2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TrackBar^  trackBar3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TrackBar^  trackBar4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;

	Image^ func;
	int popSize;
	int stepCount;
	double crossProb, mutProb;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label9;
	public:
		Form1(void)
		{
			InitializeComponent();
			
			st = BufferedGraphicsManager::Current;
			gr = this->CreateGraphics();
			System::Drawing::Rectangle rect(0,0,550,550);
			buff = st->Allocate(gr, rect);

			buff->Graphics->Clear(Color::WhiteSmoke);
			buff->Render();

			func = Image::FromFile("func1.jpg");

			popSize = 1000;
			stepCount = 100;
			crossProb = 1; 
			mutProb = 0.1;

			buff->Graphics->DrawImage(func,50-21,50);
			buff->Render();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected: 

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->trackBar3 = (gcnew System::Windows::Forms::TrackBar());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->trackBar4 = (gcnew System::Windows::Forms::TrackBar());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar4))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(371, 297);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(86, 26);
			this->button1->TabIndex = 0;
			this->button1->Text = L"New";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(422, 36);
			this->trackBar1->Maximum = 3000;
			this->trackBar1->Minimum = 1;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(180, 45);
			this->trackBar1->TabIndex = 10;
			this->trackBar1->TickFrequency = 100;
			this->trackBar1->Value = 1000;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &Form1::trackBar1_Scroll);
			// 
			// trackBar2
			// 
			this->trackBar2->Location = System::Drawing::Point(422, 80);
			this->trackBar2->Maximum = 1000;
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(180, 45);
			this->trackBar2->TabIndex = 11;
			this->trackBar2->TickFrequency = 50;
			this->trackBar2->Value = 100;
			this->trackBar2->Scroll += gcnew System::EventHandler(this, &Form1::trackBar2_Scroll);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(602, 45);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(31, 13);
			this->label1->TabIndex = 12;
			this->label1->Text = L"1000";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(603, 81);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(25, 13);
			this->label2->TabIndex = 13;
			this->label2->Text = L"100";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(603, 125);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(13, 13);
			this->label3->TabIndex = 15;
			this->label3->Text = L"1";
			// 
			// trackBar3
			// 
			this->trackBar3->Location = System::Drawing::Point(422, 125);
			this->trackBar3->Maximum = 100;
			this->trackBar3->Name = L"trackBar3";
			this->trackBar3->Size = System::Drawing::Size(180, 45);
			this->trackBar3->TabIndex = 14;
			this->trackBar3->Value = 100;
			this->trackBar3->Scroll += gcnew System::EventHandler(this, &Form1::trackBar3_Scroll);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(603, 168);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(22, 13);
			this->label4->TabIndex = 17;
			this->label4->Text = L"0.1";
			// 
			// trackBar4
			// 
			this->trackBar4->Location = System::Drawing::Point(422, 168);
			this->trackBar4->Maximum = 100;
			this->trackBar4->Name = L"trackBar4";
			this->trackBar4->Size = System::Drawing::Size(180, 45);
			this->trackBar4->TabIndex = 16;
			this->trackBar4->Value = 10;
			this->trackBar4->Scroll += gcnew System::EventHandler(this, &Form1::trackBar4_Scroll);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(349, 36);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(78, 13);
			this->label5->TabIndex = 18;
			this->label5->Text = L"Размер попул";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(351, 80);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(75, 13);
			this->label6->TabIndex = 19;
			this->label6->Text = L"Кол-во шагов";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(352, 125);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(73, 13);
			this->label7->TabIndex = 20;
			this->label7->Text = L"Вер-ть кросс";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(342, 168);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(85, 13);
			this->label8->TabIndex = 21;
			this->label8->Text = L"Вер-ть мутации";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(452, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(51, 20);
			this->textBox1->TabIndex = 22;
			this->textBox1->Text = L"2";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(371, 15);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(75, 13);
			this->label9->TabIndex = 23;
			this->label9->Text = L"Размерность";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(561, 216);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(41, 13);
			this->label10->TabIndex = 24;
			this->label10->Text = L"label10";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(652, 335);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->trackBar4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->trackBar3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->trackBar2);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Shown += gcnew System::EventHandler(this, &Form1::Form1_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar4))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 n = Convert::ToInt32(textBox1->Text);
				 Population p1(popSize, -10, 8);

				 p1.probCross = crossProb;
				 p1.probMutation = mutProb;

				 buff->Graphics->DrawImage(func,50-21,50);
				 for(int i=0; i<stepCount; i++)
					 p1.nextStep();
				 int x, y;
				 for(int i=0; i<p1.indsCount; i++)
				 {
					 x = (-9 + p1.inds[i]->chromosome[0]/(double)(1<<L)*18)/18.0*263+263/2+50;
					 y = -((-9 + p1.inds[i]->chromosome[1]/(double)(1<<L)*18)/18.0*263+263/2+50)+263+100;
					 buff->Graphics->DrawEllipse(gcnew Pen(Color::Blue), x, y, 1, 1);
				 }
				 double* res = p1.getResult();
				 x = (res[0]+1)/18.0*263+263/2+50;
				 y = -((res[1]+1)/18.0*263+263/2+50)+263+100;
				 buff->Graphics->DrawEllipse(gcnew Pen(Color::Red), x-1, y-1, 3, 3);

				 label10->Text = Convert::ToString(res[2]);

				 buff->Render();
			 }
private: System::Void Form1_Shown(System::Object^  sender, System::EventArgs^  e) {
			 buff->Render();
		 }
private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) {
			 label1->Text = Convert::ToString(trackBar1->Value);
			 popSize = trackBar1->Value;
		 }
private: System::Void trackBar2_Scroll(System::Object^  sender, System::EventArgs^  e) {
			 label2->Text = Convert::ToString(trackBar2->Value);
			 stepCount = trackBar2->Value;
		 }
private: System::Void trackBar3_Scroll(System::Object^  sender, System::EventArgs^  e) {
			 crossProb = trackBar3->Value/100.0;
			 label3->Text = Convert::ToString(crossProb);
			 
		 }
private: System::Void trackBar4_Scroll(System::Object^  sender, System::EventArgs^  e) {
			 mutProb = trackBar4->Value/100.0;
			 label4->Text = Convert::ToString(mutProb);
		 }
};
}

