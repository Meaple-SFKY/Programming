using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 监测_sql_曲线图
{
    public partial class Form1 : Form
    {
        string id;
        public Form1(string d)
        {
            InitializeComponent();
            id = d;
        }
        DataTable DT = null;
        List<DateTime> datas = new List<DateTime>();
        List<double> shujus = new List<double>();
        private void Form1_Load(object sender, EventArgs e)
        {
            
            DT=  ReadDb( conStr);
            dataGridView1.DataSource = DT;
            dataGridView1.Columns[0].Width = 150;
            dataGridView1.Columns[1].Width = 120;
            dataGridView1.Columns[2].Width = 150;
            for (int i = 0; i < DT.Rows.Count; i++)
            {
                datas.Add(DateTime.Parse(DT.Rows[i][2].ToString()).Date);
                shujus.Add(double.Parse(DT.Rows[i][1].ToString()));
            }

            chart1.Series[0].Points.DataBindXY(datas, shujus);
        }
        private void button3_Click(object sender, EventArgs e)
        {
            if(textBox1.Text=="")
            {
                MessageBox.Show("预警值不可以为空");
                textBox1.Focus();
            }
            else
            {
                string tishi = "以下日期测点超出预警值：" + "\r\n";

                for (int i = 0; i < shujus.Count; i++)
                {
                    if (shujus[i] > double.Parse(textBox1.Text))
                    {
                        tishi += datas[i].ToString("yyyy-MM-dd") + "值为：" + shujus[i] + "\r\n";
                    }
                }
                MessageBox.Show(tishi);
            }
     

        }
        string conStr = "Data Source=82.433.222.154;Initial Catalog=SQL监控;User ID=sa;Password=322223";
        public SqlConnection RquirConn()
        {
            SqlConnection con = new SqlConnection(conStr);
            con.Open();
            return con;
        }

        public DataTable ReadDb(string conStr)
        {
            DataSet ds = new DataSet();
            using (SqlConnection conn = RquirConn())
            {
                //conn.ConnectionString = conStr;
                //conn.Open();
                using (SqlCommand command = conn.CreateCommand())
                {

                    command.CommandText = "select * from Table_1 where 测点ID="+id;
                    SqlDataAdapter da = new SqlDataAdapter(command);
                   
                }
            }
            DataTable dt = new DataTable();
            dt = ds.Tables[0].Copy();
            //this.dataGridView1.DataSource = dt;
            return dt;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            this.Close();

        }
    }
}
