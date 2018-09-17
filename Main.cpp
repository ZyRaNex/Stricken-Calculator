#include "Main.h"
#include "resource.h"

class CDiabloCalcFancy : public CWinApp {
public:
	BOOL InitInstance();
};

class CDiabloCalcFancyDlg : public CDialog {
public:
	enum {IDD = IDD_DIALOG1};

	CButton	m_ctlPower;
	CButton	m_ctlSpeed;
	CButton	m_ctlSwiftHavest;
	CButton	m_ctlStrongarms;
	CButton	m_ctlChannel;

	CEdit m_ctlOUTA1;
	CEdit m_ctlOUTA2;
	CEdit m_ctlOUTA3;
	CEdit m_ctlOUTA4;
	CEdit m_ctlOUTA5;
	CEdit m_ctlOUTA6;

	CEdit m_ctlOUTB1;
	CEdit m_ctlOUTB2;
	CEdit m_ctlOUTB3;
	CEdit m_ctlOUTB4;
	CEdit m_ctlOUTB5;
	CEdit m_ctlOUTB6;

	CEdit m_ctlOUTC;


	CEdit m_ctlBossHP;

	CEdit m_ctlSheetDamage;
	CEdit m_ctlCritDamage;
	CEdit m_ctlCritChance;
	CEdit m_ctlStrickenLevel;
	CEdit m_ctlTrappedLevel;
	CEdit m_ctlZeisLevel;
	CEdit m_ctlRiftLevel;
	CEdit m_ctlcooldown;
	CEdit m_ctlEleDamage;
	CEdit m_ctlCorpseDamage;
	CEdit m_ctlTragoulDamage;
	CEdit m_ctlEssenceBonus;
	CEdit m_ctlEliteDamage;
	CEdit m_ctlKrysbinDamage;
	CEdit m_ctlLife;
	


	CDiabloCalcFancyDlg();
	~CDiabloCalcFancyDlg();

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:

	double SheetDamage;

	double CritDamage;
	double CritChance;
	int StrickenLevel;
	int TrappedLevel;
	int ZeisLevel;

	int RiftLevel;
	bool Power = false;
	bool Speed = false;
	bool SwiftHarvest = false;
	bool Strongarms = false;
	bool Channel = false;

	//double MultiplierMagicNumber = 2750000.0;
	//double MultiplierMagicNumber = 3350000.0;
	double MultiplierMagicNumber = 3000000.0;
	double BossHpMagicNumber = 123353693.16239316;
	int cooldown;

	double EleDamage;
	double CorpseDamage;
	double TragoulDamage;
	double EssenceBonus;		//from weapon+ offhand
	double EliteDamage;
	double KrysbinDamage;
	double Life;
	double CalcStrickenMulti(int StrickenStacks, bool PowerPylon, bool SpeedPylon, bool ChannelPylon);
	void Update();
	
};


CDiabloCalcFancyDlg::CDiabloCalcFancyDlg() :CDialog(CDiabloCalcFancyDlg::IDD) {

}

CDiabloCalcFancyDlg::~CDiabloCalcFancyDlg() {

}

BOOL CDiabloCalcFancyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();


	m_ctlOUTA1.SetWindowTextA("");
	m_ctlOUTA2.SetWindowTextA("");
	m_ctlOUTA3.SetWindowTextA("");
	m_ctlOUTA4.SetWindowTextA("");
	m_ctlOUTA5.SetWindowTextA("");
	m_ctlOUTA6.SetWindowTextA("");

	m_ctlOUTB1.SetWindowTextA("");
	m_ctlOUTB2.SetWindowTextA("");
	m_ctlOUTB3.SetWindowTextA("");
	m_ctlOUTB4.SetWindowTextA("");
	m_ctlOUTB5.SetWindowTextA("");
	m_ctlOUTB6.SetWindowTextA("");

	m_ctlOUTC.SetWindowTextA("");

	m_ctlBossHP.SetWindowTextA("");


	m_ctlSheetDamage.SetWindowTextA("3250000");
	m_ctlCritDamage.SetWindowTextA("4.77");
	m_ctlCritChance.SetWindowTextA("0.15");
	m_ctlStrickenLevel.SetWindowTextA("143");
	m_ctlTrappedLevel.SetWindowTextA("143");
	m_ctlZeisLevel.SetWindowTextA("137");
	m_ctlRiftLevel.SetWindowTextA("124");
	m_ctlcooldown.SetWindowTextA("84");
	m_ctlEleDamage.SetWindowTextA("0.38");
	m_ctlCorpseDamage.SetWindowTextA("0.45");
	m_ctlTragoulDamage.SetWindowTextA("2.00");
	m_ctlEssenceBonus.SetWindowTextA("39");
	m_ctlEliteDamage.SetWindowTextA("0.08");
	m_ctlKrysbinDamage.SetWindowTextA("1.00");
	m_ctlLife.SetWindowTextA("1.00");
	



	return TRUE;
}

BOOL CDiabloCalcFancy::InitInstance() {
	CDiabloCalcFancyDlg myDlg;
	m_pMainWnd = &myDlg;
	myDlg.DoModal();
	return TRUE;
}

CDiabloCalcFancy MyApp; 

BEGIN_MESSAGE_MAP(CDiabloCalcFancyDlg, CDialog)
ON_BN_CLICKED(IDC_POWER, Update)
ON_BN_CLICKED(IDC_SPEED, Update)
ON_BN_CLICKED(IDC_SWIFTHARVEST, Update)
ON_BN_CLICKED(IDC_STRONGARMS, Update)
ON_BN_CLICKED(IDC_CHANNEL, Update)

ON_EN_CHANGE(IDC_SheetDamage, Update)
ON_EN_CHANGE(IDC_CritDamage, Update)
ON_EN_CHANGE(IDC_CritChance, Update)
ON_EN_CHANGE(IDC_StrickenLevel, Update)
ON_EN_CHANGE(IDC_TrappedLevel, Update)
ON_EN_CHANGE(IDC_ZeisLevel, Update)
ON_EN_CHANGE(IDC_RiftLevel, Update)
ON_EN_CHANGE(IDC_cooldown, Update)
ON_EN_CHANGE(IDC_EleDamage, Update)
ON_EN_CHANGE(IDC_CorpseDamage, Update)
ON_EN_CHANGE(IDC_TragoulDamage, Update)
ON_EN_CHANGE(IDC_EssenceBonus, Update)
ON_EN_CHANGE(IDC_EliteDamage, Update)
ON_EN_CHANGE(IDC_KrysbinDamage, Update)
ON_EN_CHANGE(IDC_Life, Update)

END_MESSAGE_MAP()

void CDiabloCalcFancyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_POWER, m_ctlPower);
	DDX_Control(pDX, IDC_SPEED, m_ctlSpeed);
	DDX_Control(pDX, IDC_SWIFTHARVEST, m_ctlSwiftHavest);
	DDX_Control(pDX, IDC_STRONGARMS, m_ctlStrongarms);
	DDX_Control(pDX, IDC_CHANNEL, m_ctlChannel);

	DDX_Control(pDX, IDC_OUTA1, m_ctlOUTA1);
	DDX_Control(pDX, IDC_OUTA2, m_ctlOUTA2);
	DDX_Control(pDX, IDC_OUTA3, m_ctlOUTA3);
	DDX_Control(pDX, IDC_OUTA4, m_ctlOUTA4);
	DDX_Control(pDX, IDC_OUTA5, m_ctlOUTA5);
	DDX_Control(pDX, IDC_OUTA6, m_ctlOUTA6);

	DDX_Control(pDX, IDC_OUTB1, m_ctlOUTB1);
	DDX_Control(pDX, IDC_OUTB2, m_ctlOUTB2);
	DDX_Control(pDX, IDC_OUTB3, m_ctlOUTB3);
	DDX_Control(pDX, IDC_OUTB4, m_ctlOUTB4);
	DDX_Control(pDX, IDC_OUTB5, m_ctlOUTB5);
	DDX_Control(pDX, IDC_OUTB6, m_ctlOUTB6);

	DDX_Control(pDX, IDC_OUTC, m_ctlOUTC);
	
	DDX_Control(pDX, IDC_BossHP, m_ctlBossHP);

	DDX_Control(pDX, IDC_SheetDamage, m_ctlSheetDamage);
	DDX_Control(pDX, IDC_CritDamage, m_ctlCritDamage);
	DDX_Control(pDX, IDC_CritChance, m_ctlCritChance);
	DDX_Control(pDX, IDC_StrickenLevel, m_ctlStrickenLevel);
	DDX_Control(pDX, IDC_TrappedLevel, m_ctlTrappedLevel);
	DDX_Control(pDX, IDC_ZeisLevel, m_ctlZeisLevel);
	DDX_Control(pDX, IDC_RiftLevel, m_ctlRiftLevel);
	DDX_Control(pDX, IDC_cooldown, m_ctlcooldown);
	DDX_Control(pDX, IDC_EleDamage, m_ctlEleDamage);
	DDX_Control(pDX, IDC_CorpseDamage, m_ctlCorpseDamage);
	DDX_Control(pDX, IDC_TragoulDamage, m_ctlTragoulDamage);
	DDX_Control(pDX, IDC_EssenceBonus, m_ctlEssenceBonus);
	DDX_Control(pDX, IDC_EliteDamage, m_ctlEliteDamage);
	DDX_Control(pDX, IDC_KrysbinDamage, m_ctlKrysbinDamage);
	DDX_Control(pDX, IDC_Life, m_ctlLife);
	
}

double CDiabloCalcFancyDlg::CalcStrickenMulti(int StrickenStacks, bool PowerPylon, bool SpeedPylon, bool ChannelPylon)
{
	if (SpeedPylon)
	{
		if (SwiftHarvest)
		{
			StrickenStacks += (int)round(60 / 21 - 60 / 26) * 60;
		}
		else
		{
			StrickenStacks += (int)round(60 / 24 - 60 / 29) * 60;
		}
	}
	double StrickenMulti = (1 + (0.008 + StrickenLevel * 0.0001)*StrickenStacks);

	if (PowerPylon) StrickenMulti *= 3.5;

	if (SpeedPylon) StrickenMulti *= (2.0*15.0 + 20.0) / (2.0*12.0 + 20.0);

	if (ChannelPylon) StrickenMulti *= 2.0;

	return StrickenMulti;
}

//https://gist.github.com/cslarsen/1870641
static const char* short_scale[] = {
	"",
	"thousand",
	"million",
	"billion",
	"trillion",
	"quadrillion",
	"quintillion",
	"sextillion",
	"septillion"
};
const char* scale(double n, int decimals = 1, const char* units[] = short_scale)
{
	/*
	* Number of digits in n is given by
	* 10^x = n ==> x = log(n)/log(10) = log_10(n).
	*
	* So 1000 would be 1 + floor(log_10(10^3)) = 4 digits.
	*/
	int digits = (int) (n == 0 ? 0 : 1 + floor(log10l(fabs(n))));

	// determine base 10 exponential
	int exp = digits <= 4 ? 0 : 3 * ((digits - 1) / 3);

	// normalized number
	double m = n / powl(10, exp);

	// no decimals? then don't print any
	if (m - static_cast<long>(n) == 0)
		decimals = 0;

	// don't print unit for exp<3
	static char s[32];
	static const char* fmt[] = { "%1.*lf %s", "%1.*lf" };
	sprintf(s, fmt[exp<3], decimals, m, units[exp / 3]);
	return s;
}
const char* sscale(double n, int decimals = 1)
{
	static char s[32];
	strcpy(s, scale(n, decimals, short_scale));
	return s;
}




void CDiabloCalcFancyDlg::Update()
{
	//Reset
	CString Blanc;

	Blanc.Format("");

	m_ctlOUTA1.SetSel(0, -1);
	m_ctlOUTA1.ReplaceSel(Blanc);
	m_ctlOUTA2.SetSel(0, -1);
	m_ctlOUTA2.ReplaceSel(Blanc);
	m_ctlOUTA3.SetSel(0, -1);
	m_ctlOUTA3.ReplaceSel(Blanc);
	m_ctlOUTA4.SetSel(0, -1);
	m_ctlOUTA4.ReplaceSel(Blanc);
	m_ctlOUTA5.SetSel(0, -1);
	m_ctlOUTA5.ReplaceSel(Blanc);
	m_ctlOUTA6.SetSel(0, -1);
	m_ctlOUTA6.ReplaceSel(Blanc);

	m_ctlOUTB1.SetSel(0, -1);
	m_ctlOUTB1.ReplaceSel(Blanc);
	m_ctlOUTB2.SetSel(0, -1);
	m_ctlOUTB2.ReplaceSel(Blanc);
	m_ctlOUTB3.SetSel(0, -1);
	m_ctlOUTB3.ReplaceSel(Blanc);
	m_ctlOUTB4.SetSel(0, -1);
	m_ctlOUTB4.ReplaceSel(Blanc);
	m_ctlOUTB5.SetSel(0, -1);
	m_ctlOUTB5.ReplaceSel(Blanc);

	m_ctlOUTC.SetSel(0, -1);
	m_ctlOUTC.ReplaceSel(Blanc);





	CString OutputTextA[6];
	CString OutputTextB[6];
	CString OutputTextC;

	int len;

	CString strText;
	LPTSTR buffer;


	Power = m_ctlPower.GetCheck();

	Speed = m_ctlSpeed.GetCheck();
	
	SwiftHarvest = m_ctlSwiftHavest.GetCheck();
	
	Strongarms = m_ctlStrongarms.GetCheck();

	Channel = m_ctlChannel.GetCheck();


	len = m_ctlSheetDamage.LineLength(m_ctlSheetDamage.LineIndex(0));
	if (len > 0)
	{
		buffer = strText.GetBuffer(len);
		m_ctlSheetDamage.GetLine(0, buffer, len);
		strText.ReleaseBuffer(len);
		SheetDamage = _ttof(strText);
	}
	else
	{
		SheetDamage = 1;
	}

	len = m_ctlCritDamage.LineLength(m_ctlCritDamage.LineIndex(0));
	if (len > 0)
	{
		buffer = strText.GetBuffer(len);
		m_ctlCritDamage.GetLine(0, buffer, len);
		strText.ReleaseBuffer(len);
		CritDamage = _ttof(strText);
	}
	else
	{
		CritDamage = 1;
	}

	len = m_ctlCritChance.LineLength(m_ctlCritChance.LineIndex(0));
	if (len > 0)
	{
		buffer = strText.GetBuffer(len);
		m_ctlCritChance.GetLine(0, buffer, len);
		strText.ReleaseBuffer(len);
		CritChance = _ttof(strText);
	}
	else
	{
		CritChance = 1;
	}

	len = m_ctlStrickenLevel.LineLength(m_ctlStrickenLevel.LineIndex(0));
	if (len > 0)
	{
		buffer = strText.GetBuffer(len);
		m_ctlStrickenLevel.GetLine(0, buffer, len);
		strText.ReleaseBuffer(len);
		StrickenLevel = _ttoi(strText);
	}
	else
	{
		StrickenLevel = 1;
	}

	len = m_ctlTrappedLevel.LineLength(m_ctlTrappedLevel.LineIndex(0));
	if (len > 0)
	{
		buffer = strText.GetBuffer(len);
		m_ctlTrappedLevel.GetLine(0, buffer, len);
		strText.ReleaseBuffer(len);
		TrappedLevel = _ttoi(strText);
	}
	else
	{
		TrappedLevel = 1;
	}

	len = m_ctlZeisLevel.LineLength(m_ctlZeisLevel.LineIndex(0));
	if (len > 0)
	{
		buffer = strText.GetBuffer(len);
		m_ctlZeisLevel.GetLine(0, buffer, len);
		strText.ReleaseBuffer(len);
		ZeisLevel = _ttoi(strText);
	}
	else
	{
		ZeisLevel = 1;
	}

	len = m_ctlRiftLevel.LineLength(m_ctlRiftLevel.LineIndex(0));
	if (len > 0)
	{
		buffer = strText.GetBuffer(len);
		m_ctlRiftLevel.GetLine(0, buffer, len);
		strText.ReleaseBuffer(len);
		RiftLevel = _ttoi(strText);
	}
	else
	{
		RiftLevel = 1;
	}

	len = m_ctlcooldown.LineLength(m_ctlcooldown.LineIndex(0));
	if (len > 0)
	{
		buffer = strText.GetBuffer(len);
		m_ctlcooldown.GetLine(0, buffer, len);
		strText.ReleaseBuffer(len);
		cooldown = _ttoi(strText);
	}
	else
	{
		cooldown = 1;
	}

	len = m_ctlEleDamage.LineLength(m_ctlEleDamage.LineIndex(0));
	if (len > 0)
	{
		buffer = strText.GetBuffer(len);
		m_ctlEleDamage.GetLine(0, buffer, len);
		strText.ReleaseBuffer(len);
		EleDamage = _ttof(strText);
	}
	else
	{
		EleDamage = 1;
	}

	len = m_ctlCorpseDamage.LineLength(m_ctlCorpseDamage.LineIndex(0));
	if (len > 0)
	{
		buffer = strText.GetBuffer(len);
		m_ctlCorpseDamage.GetLine(0, buffer, len);
		strText.ReleaseBuffer(len);
		CorpseDamage = _ttof(strText);
	}
	else
	{
		CorpseDamage = 1;
	}

	len = m_ctlTragoulDamage.LineLength(m_ctlTragoulDamage.LineIndex(0));
	if (len > 0)
	{
		buffer = strText.GetBuffer(len);
		m_ctlTragoulDamage.GetLine(0, buffer, len);
		strText.ReleaseBuffer(len);
		TragoulDamage = _ttof(strText);
	}
	else
	{
		TragoulDamage = 1;
	}

	len = m_ctlEssenceBonus.LineLength(m_ctlEssenceBonus.LineIndex(0));
	if (len > 0)
	{
		buffer = strText.GetBuffer(len);
		m_ctlEssenceBonus.GetLine(0, buffer, len);
		strText.ReleaseBuffer(len);
		EssenceBonus = _ttof(strText);
	}
	else
	{
		EssenceBonus = 1;
	}

	len = m_ctlEliteDamage.LineLength(m_ctlEliteDamage.LineIndex(0));
	if (len > 0)
	{
		buffer = strText.GetBuffer(len);
		m_ctlEliteDamage.GetLine(0, buffer, len);
		strText.ReleaseBuffer(len);
		EliteDamage = _ttof(strText);
	}
	else
	{
		EliteDamage = 1;
	}

	len = m_ctlKrysbinDamage.LineLength(m_ctlKrysbinDamage.LineIndex(0));
	if (len > 0)
	{
		buffer = strText.GetBuffer(len);
		m_ctlKrysbinDamage.GetLine(0, buffer, len);
		strText.ReleaseBuffer(len);
		KrysbinDamage = _ttof(strText);
	}
	else
	{
		KrysbinDamage = 1;
	}

	len = m_ctlKrysbinDamage.LineLength(m_ctlLife.LineIndex(0));
	if (len > 0)
	{
		buffer = strText.GetBuffer(len);
		m_ctlLife.GetLine(0, buffer, len);
		strText.ReleaseBuffer(len);
		Life = _ttof(strText);
	}
	else
	{
		Life = 1.0;
	}




	double NoCritDamage = SheetDamage / (1 + CritChance * CritDamage);
	double FullCritDamage = NoCritDamage * (1.0 + CritDamage);
	FullCritDamage *= (1.0 + EleDamage);

	if(Strongarms)
	{
		FullCritDamage *= (1.55+0.29 + CorpseDamage);//1+0.1+0.1+0.25+0.1 +0.29   2x toxin unity falter and rend + strongarms
	}
	else
	{
		FullCritDamage *= (1.55 + CorpseDamage);//1+0.1+0.1+0.25+0.1    2x toxin unity falter and rend
	}

	FullCritDamage *= (1.0 + 0.15 + TrappedLevel * 0.003);
	FullCritDamage *= (1.0 + 0.2 + ZeisLevel * 0.004);
	FullCritDamage *= (1.0 + TragoulDamage);
	FullCritDamage *= (1.0 + (290 + EssenceBonus)*0.005);
	FullCritDamage *= (1.0 + EliteDamage);
	FullCritDamage *= (1.0 + 3*KrysbinDamage);


	double BossHp = BossHpMagicNumber * pow(1.17, RiftLevel);				//123353693.16239316
	double BossCursedHP = BossHp * 0.85;

	double RealBaseDamage = FullCritDamage * MultiplierMagicNumber; 
	double ReStrickenMulti = BossCursedHP / RealBaseDamage;


	CString Text;

	Text.Format("%s", sscale(BossHp));

	m_ctlBossHP.SetSel(0, -1);
	m_ctlBossHP.ReplaceSel(Text);

	int StrickenStacksPerRota;
	if (SwiftHarvest)
	{
		StrickenStacksPerRota = (int)round((60.0 / 25.0)* (double)cooldown);
	}
	else
	{
		StrickenStacksPerRota = (int)round((60.0 / 29.0)* (double)cooldown);
	}

	StrickenStacksPerRota = (int)round(StrickenStacksPerRota*0.9);

	int seconds, minutes;

	int MinStacks = 10000;
	int MinRotas = 0;
	for (int i = 0; i < StrickenStacksPerRota; i++)
	{
		int MomentaryStrickenStacks = i;
		double BossStrickenMulti = ReStrickenMulti;
		for (int Rotas = 1; Rotas < 10; Rotas++)
		{

			BossStrickenMulti -= CalcStrickenMulti(MomentaryStrickenStacks, Power,  Speed, Channel);

			if (BossStrickenMulti < 0)//dead
			{
				if (MinStacks > MomentaryStrickenStacks)
				{
					MinStacks = MomentaryStrickenStacks;
					MinRotas = Rotas;
				}
				break;
			}
			else
			{
				BossStrickenMulti += CalcStrickenMulti(MomentaryStrickenStacks, Power, Speed, Channel);
				BossStrickenMulti -= CalcStrickenMulti(MomentaryStrickenStacks, false, false, false);
			}
			MomentaryStrickenStacks += StrickenStacksPerRota;
		}
	}
	int RequiredStrickenStacks = MinStacks % StrickenStacksPerRota;

	double LifePercent = 100;
	for (int i = 0; i < MinRotas ; i++)
	{
		if (i == (MinRotas - 1) && (Power || Speed || Channel))//power
		{
			LifePercent -= 100 * (CalcStrickenMulti(RequiredStrickenStacks + i * StrickenStacksPerRota, Power, Speed, Channel)) / (ReStrickenMulti / 0.85);
		}
		else
		{
			LifePercent -= 100 * (CalcStrickenMulti(RequiredStrickenStacks + i * StrickenStacksPerRota, false, false, false)) / (ReStrickenMulti / 0.85);
		}
		if(i<6)OutputTextA[i].Format("%.1f", LifePercent);
	}


	double time;

	for (int i = 0; i < MinRotas; i++)
	{
		if (SwiftHarvest)
		{
			time = (double)((RequiredStrickenStacks + i * StrickenStacksPerRota)/0.9) / (60.0 / 25.0);
		}
		else
		{
			time = (double)((RequiredStrickenStacks + i * StrickenStacksPerRota)/0.9) / (60.0 / 29.0);
		}

		seconds = (int)round(time);
		minutes = seconds / 60;
	
		if (i<6)OutputTextA[i].Format("%d  %6d  %d:%02d   HP:%s",i , RequiredStrickenStacks + i * StrickenStacksPerRota, int(minutes % 60), int(seconds % 60), OutputTextA[i]);
	}


	MinStacks = 10000;
	MinRotas = 0;

	for (int i = 0; i < StrickenStacksPerRota; i++)
	{
		int MomentaryStrickenStacks = i;
		double BossStrickenMulti = ReStrickenMulti;
		for (int Rotas = 1; Rotas < 10; Rotas++)
		{

			if (Rotas>1)BossStrickenMulti -= CalcStrickenMulti(MomentaryStrickenStacks, Power, Speed, Channel);

			if (BossStrickenMulti < 0)//dead
			{
				if (MinStacks > MomentaryStrickenStacks)
				{
					MinStacks = MomentaryStrickenStacks;
					MinRotas = Rotas;
				}
				break;
			}
			else
			{
				if (Rotas > 1)
				{
					BossStrickenMulti += CalcStrickenMulti(MomentaryStrickenStacks, Power, Speed, Channel);
					BossStrickenMulti -= CalcStrickenMulti(MomentaryStrickenStacks, false, false, false);
				}
			}
			MomentaryStrickenStacks += StrickenStacksPerRota;
		}
	}
	RequiredStrickenStacks = MinStacks % StrickenStacksPerRota;

	LifePercent = 100;
	for (int i = 0; i < MinRotas; i++)
	{
		if (i == (MinRotas - 1) && Power)//power
		{
			if (i>0)LifePercent -= 100 * (CalcStrickenMulti(RequiredStrickenStacks + i * StrickenStacksPerRota, Power, Speed, Channel)) / (ReStrickenMulti / 0.85);
		}
		else
		{
			if (i>0)LifePercent -= 100 * (CalcStrickenMulti(RequiredStrickenStacks + i * StrickenStacksPerRota, false, false, false)) / (ReStrickenMulti / 0.85);
		}
		if (i<6)OutputTextB[i].Format("%.1f", LifePercent);
	}


	for (int i = 0; i < MinRotas; i++)
	{
		if (SwiftHarvest)
		{
			time = (double)((RequiredStrickenStacks + i * StrickenStacksPerRota)/0.9) / (60.0 / 25.0);
		}
		else
		{
			time = (double)((RequiredStrickenStacks + i * StrickenStacksPerRota)/0.9) / (60.0 / 29.0);
		}

		seconds = (int)round(time);
		minutes = seconds / 60;

		if (i<6)OutputTextB[i].Format("%d  %6d  %d:%02d   HP:%s", i - 1, RequiredStrickenStacks + i * StrickenStacksPerRota, int(minutes % 60), int(seconds % 60), OutputTextB[i]);
	}



	MinStacks = 10000;
	MinRotas = 0;
	for (int i = 0; i < 9*StrickenStacksPerRota; i++)
	{
			//if BossStrickenMulti -= CalcStrickenMulti(MomentaryStrickenStacks, Power, Speed);
			double FullMulti = (ReStrickenMulti*(Life-0.15)/ (1.0 - 0.15)) - CalcStrickenMulti(i, Power, Speed, Channel);

			if (FullMulti < 0)//dead
			{
				MinStacks = i;
				break;
			}
	}
	RequiredStrickenStacks = MinStacks;




	LifePercent = 100;

	LifePercent -= 100 * (CalcStrickenMulti(RequiredStrickenStacks, Power, Speed, Channel)) / (ReStrickenMulti / 0.85);



	if (SwiftHarvest)
	{
		time = (double)(RequiredStrickenStacks/0.9) / (60.0 / 25.0);
	}
	else
	{
		time = (double)(RequiredStrickenStacks/0.9) / (60.0 / 29.0);
	}

	seconds = (int)round(time);
	minutes = seconds / 60;

	OutputTextC.Format("%d  %6d  %d:%02d   HP:%s", 0, RequiredStrickenStacks, int(minutes % 60), int(seconds % 60), OutputTextC);


	//CString strLine;
	//strLine.Format("%d", StrickenLevel);

	m_ctlOUTA1.SetSel(0, -1);
	m_ctlOUTA1.ReplaceSel(OutputTextA[0]);
	m_ctlOUTA2.SetSel(0, -1);
	m_ctlOUTA2.ReplaceSel(OutputTextA[1]);
	m_ctlOUTA3.SetSel(0, -1);
	m_ctlOUTA3.ReplaceSel(OutputTextA[2]);
	m_ctlOUTA4.SetSel(0, -1);
	m_ctlOUTA4.ReplaceSel(OutputTextA[3]);
	m_ctlOUTA5.SetSel(0, -1);
	m_ctlOUTA5.ReplaceSel(OutputTextA[4]);
	m_ctlOUTA6.SetSel(0, -1);
	m_ctlOUTA6.ReplaceSel(OutputTextA[5]);

	m_ctlOUTB1.SetSel(0, -1);
	m_ctlOUTB1.ReplaceSel(OutputTextB[1]);
	m_ctlOUTB2.SetSel(0, -1);
	m_ctlOUTB2.ReplaceSel(OutputTextB[2]);
	m_ctlOUTB3.SetSel(0, -1);
	m_ctlOUTB3.ReplaceSel(OutputTextB[3]);
	m_ctlOUTB4.SetSel(0, -1);
	m_ctlOUTB4.ReplaceSel(OutputTextB[4]);
	m_ctlOUTB5.SetSel(0, -1);
	m_ctlOUTB5.ReplaceSel(OutputTextB[5]);

	m_ctlOUTC.SetSel(0, -1);
	m_ctlOUTC.ReplaceSel(OutputTextC);
}

