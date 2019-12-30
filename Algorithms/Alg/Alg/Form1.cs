using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using ZedGraph;

namespace Alg
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            PointPairList list = new PointPairList();
            GraphPane pane = zedGraph.GraphPane;

            pane.XAxis.Title.Text = "Ось X";
            pane.YAxis.Title.Text = "Ось Y";
            pane.Title.Text = "Бабочка";

            //for (double x = -7; x <7; x+=0.001)
            //{
            //    double y = 2 * Math.Sqrt((-Math.Abs(Math.Abs(x) - 1)) * Math.Abs(3 - Math.Abs(
            //    x)) / ((Math.Abs(x) - 1) * (3 - Math.Abs(x)))) * (1 + Math.Abs(Math.Abs(x) - 3) / (Math.Abs(x) - 3)) *
            //    Math.Sqrt(1 - Math.Pow((x / 7), 2)) + (5 + 0.97 * (Math.Abs(x - 0.5) + Math.Abs(x + 0.5)) - 3 * (Math.Abs(
            //    x - 0.75) + Math.Abs(x + 0.75))) *
            //    (1 + Math.Abs(1 - Math.Abs(x)) / (1 - Math.Abs(x)));
            //    list.Add(x, y);
            //    
            //}
            //for(double x = -7; x < 7; x += 0.001)
            //{
            //    double y = (-3) * Math.Sqrt(1 - Math.Pow((x / 7), 2)) * Math.Sqrt(Math.Abs(Math.Abs(x) - 4) / (Math.Abs(x) - 4));
            //    list.Add(x, y);
            //}
            //
            //for (double x = -7; x < 7; x += 0.001)
            //{
            //    double y = Math.Abs(x / 2)-Math.Pow(0.0913722 * x,2) - 3 + Math.Sqrt(1 - Math.Pow((Math.Abs(Math.Abs(x) - 2) - 1),2));
            //    list.Add(x, y);
            //}
            //for (double x = -7; x < 7; x += 0.001)
            //{
            //    double y = (2.71052 +1.5 - 0.5 * Math.Abs(x) - 1.35526 * Math.Sqrt(4 - Math.Pow((Math.Abs(x) - 1) , 2))) * Math.Sqrt(Math.Abs(
            //    Math.Abs(x) - 1) / (Math.Abs(x) - 1)) + 0.9;
            //    list.Add(x, y);
            //}

            for (double t = 0; t <= 12 * Math.PI; t+=0.001)
            {
                double x = Math.Sin(t) * (Math.Pow(Math.E, Math.Cos(t)) - 2 * Math.Cos(4 * t) + Math.Pow(Math.Sin(t / 12), 5));
                double y = Math.Cos(t) * (Math.Pow(Math.E, Math.Cos(t)) - 2 * Math.Cos(4 * t) + Math.Pow(Math.Sin(t / 12), 5));
                list.Add(x, y);
            }

            LineItem myCurve = pane.AddCurve("", list, Color.Red, SymbolType.None);
            zedGraph.AxisChange();
            zedGraph.Invalidate();
        }

    }
}

