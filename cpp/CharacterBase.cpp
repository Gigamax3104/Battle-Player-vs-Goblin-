#include	"../h/CharacterBase.h"
using namespace std;

// デフォルトコンストラクタ
CharacterBase::CharacterBase()
	: m_save_hp(0), m_save_power(0.0), m_save_difence(0.0), m_save_mitigation(0)
	, m_save_dodgeProbability(0), m_hp(0), m_power(0.0), m_difence(0.0)
	, m_mitigation(0), m_dodgeProbability(0), m_item(nullptr), m_itemNumber(0)
	, m_name(nullptr), m_pos() {}

// 引数つきコンストラクタ
CharacterBase::CharacterBase(int hp, double power, double difence, int mitigation, int dodgeProb, int itemNumber, const char* name, const Vector2& pos)
	: m_save_hp(hp), m_save_power(power), m_save_difence(difence)
	, m_save_mitigation(mitigation), m_save_dodgeProbability(dodgeProb)
	, m_hp(hp), m_power(power), m_difence(difence), m_mitigation(mitigation)
	, m_dodgeProbability(dodgeProb), m_item(nullptr), m_itemNumber(itemNumber)
	, m_name(nullptr), m_pos(pos)
{
	if (name) m_name = _strdup(name); // strdup 等で名前を複製

	if (itemNumber > 0) m_item = new int[itemNumber]();
}

// コピーコンストラクタ
CharacterBase::CharacterBase(const CharacterBase& other)
	: m_save_hp(other.m_save_hp), m_save_power(other.m_save_power)
	, m_save_difence(other.m_save_difence)
	, m_save_mitigation(other.m_save_mitigation)
	, m_save_dodgeProbability(other.m_save_dodgeProbability)
	, m_hp(other.m_hp), m_power(other.m_power), m_difence(other.m_difence)
	, m_mitigation(other.m_mitigation)
	, m_dodgeProbability(other.m_dodgeProbability), m_item(nullptr)
	, m_itemNumber(other.m_itemNumber), m_name(nullptr), m_pos(other.m_pos)
{
	if (other.m_name) m_name = _strdup(other.m_name);

	if (other.m_itemNumber > 0 && other.m_item) {
		m_item = new int[other.m_itemNumber];
		memcpy(m_item, other.m_item, sizeof(int) * other.m_itemNumber);
	}
}

CharacterBase::~CharacterBase() {
	if (m_name != nullptr) {
		if (*m_name == '\0' || *m_name == NULL) delete m_name;
		else delete[] m_name;

		m_name = nullptr;
	}
}

void CharacterBase::ParamaterShow(InputManager* input) {
	input->SetCursorPosition(Vector2(30, 0));

	cout << "Name : " << m_name << endl
		<< "HP : " << m_hp << endl
		<< "Attack : " << m_power << endl
		<< "Difence : " << m_difence << endl
		<< "Mitigation : " << m_mitigation << "%" << endl
		<< "Dodge :" << m_dodgeProbability << "%" << endl;

	input->SetCursorPosition(Vector2(27, 0));
}