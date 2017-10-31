using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using VkClient.Forms;
using VkNet;
using VkNet.Enums.Filters;

namespace VkClient
{
    public partial class RegistrationForm : Form
    {
        VkApi vk;
        public RegistrationForm()
        {
            InitializeComponent();
            vk = new VkApi();
        }

        private void RegistrationForm_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            ulong appID = 6241287;
            string login = tbLogin.Text;
            string password = tbPassword.Text;
            Settings scope = Settings.All;
            Func<string> code = () =>
            {
                TwoFactorAuthorizationForm form = new TwoFactorAuthorizationForm();
                form.ShowDialog();
                return form.Code;
            };
           
            vk.Authorize(new ApiAuthParams
            {
                ApplicationId = appID,
                Login = login,
                Password = password,
                Settings = scope,
                TwoFactorAuthorization = code
            });

            this.Visible = false;
            MainForm mainForm = new MainForm(vk);
            mainForm.ShowDialog();
            this.Close();
                
        }
    }
}
