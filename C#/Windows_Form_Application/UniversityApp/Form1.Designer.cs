namespace UniversityApp
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.listBox2 = new System.Windows.Forms.ListBox();
            this.btn_Add = new System.Windows.Forms.Button();
            this.btn_Rmv = new System.Windows.Forms.Button();
            this.btn_Addall = new System.Windows.Forms.Button();
            this.btn_Rmvall = new System.Windows.Forms.Button();
            this.btn_finalize = new System.Windows.Forms.Button();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.SuspendLayout();
            // 
            // listBox1
            // 
            this.listBox1.FormattingEnabled = true;
            this.listBox1.ItemHeight = 16;
            this.listBox1.Location = new System.Drawing.Point(53, 27);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(395, 436);
            this.listBox1.TabIndex = 0;
            // 
            // listBox2
            // 
            this.listBox2.FormattingEnabled = true;
            this.listBox2.ItemHeight = 16;
            this.listBox2.Location = new System.Drawing.Point(965, 27);
            this.listBox2.Name = "listBox2";
            this.listBox2.Size = new System.Drawing.Size(395, 436);
            this.listBox2.TabIndex = 1;
            // 
            // btn_Add
            // 
            this.btn_Add.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btn_Add.Location = new System.Drawing.Point(659, 50);
            this.btn_Add.Name = "btn_Add";
            this.btn_Add.Size = new System.Drawing.Size(109, 51);
            this.btn_Add.TabIndex = 2;
            this.btn_Add.Text = "Add";
            this.btn_Add.UseVisualStyleBackColor = true;
            this.btn_Add.Click += new System.EventHandler(this.btn_Add_Click);
            // 
            // btn_Rmv
            // 
            this.btn_Rmv.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btn_Rmv.Location = new System.Drawing.Point(643, 143);
            this.btn_Rmv.Name = "btn_Rmv";
            this.btn_Rmv.Size = new System.Drawing.Size(152, 51);
            this.btn_Rmv.TabIndex = 3;
            this.btn_Rmv.Text = "Remove";
            this.btn_Rmv.UseVisualStyleBackColor = true;
            this.btn_Rmv.Click += new System.EventHandler(this.btn_Rmv_Click);
            // 
            // btn_Addall
            // 
            this.btn_Addall.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btn_Addall.Location = new System.Drawing.Point(649, 232);
            this.btn_Addall.Name = "btn_Addall";
            this.btn_Addall.Size = new System.Drawing.Size(136, 51);
            this.btn_Addall.TabIndex = 4;
            this.btn_Addall.Text = "Add All";
            this.btn_Addall.UseVisualStyleBackColor = true;
            this.btn_Addall.Click += new System.EventHandler(this.btn_Addall_Click);
            // 
            // btn_Rmvall
            // 
            this.btn_Rmvall.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btn_Rmvall.Location = new System.Drawing.Point(628, 317);
            this.btn_Rmvall.Name = "btn_Rmvall";
            this.btn_Rmvall.Size = new System.Drawing.Size(173, 51);
            this.btn_Rmvall.TabIndex = 5;
            this.btn_Rmvall.Text = "Remove All";
            this.btn_Rmvall.UseVisualStyleBackColor = true;
            this.btn_Rmvall.Click += new System.EventHandler(this.btn_Rmvall_Click);
            // 
            // btn_finalize
            // 
            this.btn_finalize.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btn_finalize.Location = new System.Drawing.Point(643, 402);
            this.btn_finalize.Name = "btn_finalize";
            this.btn_finalize.Size = new System.Drawing.Size(142, 51);
            this.btn_finalize.TabIndex = 6;
            this.btn_finalize.Text = "Finalize";
            this.btn_finalize.UseVisualStyleBackColor = true;
            this.btn_finalize.Click += new System.EventHandler(this.btn_finalize_Click);
            // 
            // dataGridView1
            // 
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(53, 500);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowHeadersWidth = 51;
            this.dataGridView1.RowTemplate.Height = 24;
            this.dataGridView1.Size = new System.Drawing.Size(1307, 333);
            this.dataGridView1.TabIndex = 7;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1445, 856);
            this.Controls.Add(this.dataGridView1);
            this.Controls.Add(this.btn_finalize);
            this.Controls.Add(this.btn_Rmvall);
            this.Controls.Add(this.btn_Addall);
            this.Controls.Add(this.btn_Rmv);
            this.Controls.Add(this.btn_Add);
            this.Controls.Add(this.listBox2);
            this.Controls.Add(this.listBox1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.ListBox listBox2;
        private System.Windows.Forms.Button btn_Add;
        private System.Windows.Forms.Button btn_Rmv;
        private System.Windows.Forms.Button btn_Addall;
        private System.Windows.Forms.Button btn_Rmvall;
        private System.Windows.Forms.Button btn_finalize;
        private System.Windows.Forms.DataGridView dataGridView1;
    }
}

