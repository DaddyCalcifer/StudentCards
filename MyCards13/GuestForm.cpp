#include "GuestForm.h"

MyCards13::GuestForm::GuestForm()
{
	InitializeComponent();
	math_f->Text = F_MATH + ": " + GetLineCountS("math_fac.cdb");
	tech_f->Text = F_TECH + ": " + GetLineCountS("tech_fac.cdb");
	railway_f->Text = F_RAILWAY + ": " + GetLineCountS("railway_fac.cdb");
	roadt_f->Text = F_ROAD_TRANSPORT + ": " + GetLineCountS("roadt_fac.cdb");
	ist_f->Text = F_ISTECH + ": " + GetLineCountS("ist_fac.cdb");
	int_f->Text = F_INTERNATIONAL + ": " + GetLineCountS("inat_fac.cdb");
}