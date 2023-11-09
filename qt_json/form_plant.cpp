#include "form_plant.h"

JsonFormPlant::JsonFormPlant()
{

}

void JsonFormPlant::SetKey(const QString &str)
{
    m_jsonFormInfo.key = str;
}

void JsonFormPlant::SetType(const QString &str)
{
    if (str == "int") {
        m_jsonFormInfo.type = JsonMemberTypeInt;
    }
    else if (str == "string") {
        m_jsonFormInfo.type = JsonMemberTypeStr;
    } else if (str == "bool") {
        m_jsonFormInfo.type = JsonMemberTypeBool;
    }
}

void JsonFormPlant::SetValue(const QString &str)
{
    m_jsonFormInfo.value = str;
}

void JsonFormPlant::SetStepSize(int32_t step)
{
    m_jsonFormInfo.step = step;
}

JsonFormInfo JsonFormPlant::GetCurrentJsonForm()
{
    return m_jsonFormInfo;
}

void JsonFormPlant::AddJsonForm(JsonFormInfo &jsonFormInfo)
{
    m_jsonFormPlantItems.emplace_back(jsonFormInfo);
}

Json JsonFormPlant::GenerateFormJson(int32_t num)
{
    Json ret;
    for (int32_t i = 0; i < num; i ++) {
        Json item;
        for (auto & jsonInfo : m_jsonFormPlantItems) {
            if (jsonInfo.type == JsonMemberTypeInt) {
                auto value = std::stoll(jsonInfo.value.toStdString());
                value += jsonInfo.diff;
                item[jsonInfo.key.toStdString()] = value;
                jsonInfo.diff += jsonInfo.step;
            } else if (jsonInfo.type == JsonMemberTypeStr) {
                item[jsonInfo.key.toStdString()] = jsonInfo.value.toStdString();
            } else if (jsonInfo.type == JsonMemberTypeBool) {
                if (jsonInfo.value == true) {
                    item[jsonInfo.key.toStdString()] = true;
                } else {
                    item[jsonInfo.key.toStdString()] = true;
                }
            }
        }

        ret.push_back(item);
    }

    for (auto & jsonInfo : m_jsonFormPlantItems) {
        if (jsonInfo.type == JsonMemberTypeInt) {
            jsonInfo.diff = 0;
        }
    }


    return ret;
}

Json JsonFormPlant::PriviewJsonInfo()
{
    Json item;
    for (auto & jsonInfo : m_jsonFormPlantItems) {
        if (jsonInfo.type == JsonMemberTypeInt) {
            auto value = std::stoll(jsonInfo.value.toStdString());
            value += jsonInfo.diff;
            item[jsonInfo.key.toStdString()] = value;
        } else if (jsonInfo.type == JsonMemberTypeStr) {
            item[jsonInfo.key.toStdString()] = jsonInfo.value.toStdString();
        } else if (jsonInfo.type == JsonMemberTypeBool) {
            if (jsonInfo.value == true) {
                item[jsonInfo.key.toStdString()] = true;
            } else {
                item[jsonInfo.key.toStdString()] = true;
            }
        }
    }
    return item;
}
