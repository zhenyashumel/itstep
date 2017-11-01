using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DemoGDI
{
    public partial class MainForm : Form
    {
    
        public MainForm()
        {
            InitializeComponent();
        }

        private void MainForm_Paint(object sender, PaintEventArgs e)
        {
            Graphics grf = e.Graphics;

            grf.DrawEllipse(new Pen(Color.Red, 4), 50, 50, 150, 150);

            Pen pen = new Pen(Color.Green, 4);
            grf.DrawBezier(pen, new Point(150, 150), new Point(250, 250), new Point(300, 300), new Point(300, 150));
            grf.DrawEllipse(new Pen(Color.Red, 4), 200, 40, 150, 150);
            SolidBrush solidBrush = new SolidBrush(Color.Yellow);
            SolidBrush solidBrush1 = new SolidBrush(Color.Aqua);
            grf.FillEllipse(solidBrush, new Rectangle(50, 50, 150, 150));
            grf.FillEllipse(solidBrush1, new Rectangle(200, 40, 150, 150));
            LinearGradientBrush gradient = new LinearGradientBrush(new Point(200, 0), new Point(350, 0), Color.Green, Color.Aqua);
            grf.FillEllipse(gradient, new Rectangle(200, 40, 150, 150));
            grf.DrawArc(new Pen(Color.Green, 4), new Rectangle(155, 160, 200, 150),0, 150);
            Image img = Image.FromFile("Image.png");
            TextureBrush texture = new TextureBrush(img);

            grf.DrawImage(img, 410, 50, 200, 250);

           
            Graphics grfImage = Graphics.FromImage(img);
            grfImage.DrawString("Looool...", new Font("Comic Sans MS",14), solidBrush,20,200);
            grf.DrawImage(img, 410, 50, 200, 250);
        }
    }
}
