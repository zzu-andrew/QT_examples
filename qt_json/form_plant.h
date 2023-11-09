#ifndef FORM_PLANT_H
#define FORM_PLANT_H

#include <vector>
#include <QString>


#include "nlohmann/json.hpp"
using Json = nlohmann::json;


enum JsonMemberType {
    JsonMemberTypeInt = 1,
    JsonMemberTypeStr = 2,
    JsonMemberTypeBool = 3,
};

struct JsonFormInfo
{
    QString key;
    JsonMemberType type;
    QString value;
    int32_t step{0};
    int64_t diff{0};  // 总共差值
};


class JsonFormPlant
{
public:
    JsonFormPlant();

    // key值
    void SetKey(const QString & str);
    // key值
    void SetType(const QString & str);
    // value 值
    void SetValue(const QString & str);
    // 步长
    void SetStepSize(int32_t step);

    JsonFormInfo GetCurrentJsonForm();

    void AddJsonForm(JsonFormInfo & jsonFormInfo);

    Json GenerateFormJson(int32_t num);

    Json PriviewJsonInfo();

private:
    JsonFormInfo m_jsonFormInfo;

    std::vector<JsonFormInfo> m_jsonFormPlantItems;

};

#endif // FORM_PLANT_H
